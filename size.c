#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include "stack.h"
#include<gtk/gtk.h>
static GtkWidget *window, *wid[25][25];
stack s1, s2, s3;
void solvenine(){
	init(&s1);
	init(&s2);
	init(&s3);
	int i, j, r, c;
	for(i = 0; i < 9; i++){
        	for(j = 0; j < 9; j++){
            		if(sudoku[i][j] == 0){
                		r = 1;
           			c = 0;
                		line:
                		r = c + 1;
                //check r is between  1 to n or not and it should not be notwant. 
                		while(r < (9 + 1)) {		
                   		 	if(!insquare(i, j, r) && !inrow(i, j, r) && !incolumn(i, j, r)) {
                     	   			push(&s1, i);
                        			push(&s2, j);
                        			push(&s3, r);
                        			sudoku[i][j] = r;
                        			break;
                    			}
					else {
                        			r++;
						//printf("%d\n", r);
                        			if(r >= (9 + 1) ) {
                            				sudoku[i][j] = 0;
                            				if(isempty(&s1)){
                                				printf("Sudoku is not solveable\n");
                                				exit(0);
                            				}
                            			i = pop(&s1);
                            			j = pop(&s2);
                            			c = pop(&s3);
                            			goto line;
                        		}
                    		}
                	}
                	if(r >= (9 + 1) ) {
                    		sudoku[i][j] = 0;
                    		if(isempty(&s1)){
                        		printf("Sudoku is not solveable\n");
                        		exit(0);
                    		}
                    		i = pop(&s1);
                    		j = pop(&s2);
                    		c = pop(&s3);
                    		goto line;
                	}
            	}
        }
    }


}
void solve16(){
	init(&s1);
	init(&s2);
	init(&s3);
	int i, j, r, c;
	for(i = 0; i < 16; i++){
        	for(j = 0; j < 16; j++){
            		if(sudoku[i][j] == 0){
                		r = 1;
           			c = 0;
                		line:
                		r = c + 1;
                //check r is between  1 to n or not and it should not be notwant. 
                		while(r < (16 + 1)) {		
                    			if(!insquare16(i, j, r) && !inrow16(i, j, r) && !incolumn16(i, j, r)) {
                        			push(&s1, i);
                        			push(&s2, j);
                        			push(&s3, r);
                        			sudoku[i][j] = r;
                        			break;
                    			}	
					else {
                        			r++;
						//printf("%d\n", r);
                        			if(r >= (16 + 1) ) {
                            				sudoku[i][j] = 0;
                            				if(isempty(&s1)){
                            		    			printf("Sudoku is not solveable\n");
                                				exit(0);
                            				}
                            				i = pop(&s1);
                            				j = pop(&s2);
                            				c = pop(&s3);
                            				goto line;
                        			}
                    			}
                		}
                		if(r >= (16 + 1) ) {
                    			sudoku[i][j] = 0;
                    			if(isempty(&s1)){
                        			printf("Sudoku is not solveable\n");
                        			exit(0);
                    			}
                    			i = pop(&s1);
                    			j = pop(&s2);
                    			c = pop(&s3);
                    			goto line;
                		}
            		}
        	}
    	}


}
void solve25(){
	init(&s1);
	init(&s2);
	init(&s3);
	int i, j, r, c;
	for(i = 0; i < 25; i++){
        	for(j = 0; j < 25; j++){
          		  if(sudoku[i][j] == 0){
          		     	r = 1;
	           		c = 0;
                		line:
                		r = c + 1;
                //check r is between  1 to n or not and it should not be notwant. 
                		while(r < (25 + 1)) {		
                    			if(!insquare25(i, j, r) && !inrow25(i, j, r) && !incolumn25(i, j, r)) {
                        			push(&s1, i);
                        			push(&s2, j);
                        			push(&s3, r);
                        			sudoku[i][j] = r;
                        			break;
                    			}
					else {
                    				r++;
						//printf("%d\n", r);
                        			if(r >= (25 + 1) ) {
                            				sudoku[i][j] = 0;
                            				if(isempty(&s1)){
                                				printf("Sudoku is not solveable\n");
                                				exit(0);
                            				}
                            				i = pop(&s1);
                            				j = pop(&s2);
                            				c = pop(&s3);
                            				goto line;
                        			}
                    			}
                		}
                		if(r >= (25 + 1) ) {
                    			sudoku[i][j] = 0;
                    			if(isempty(&s1)){
                        			printf("Sudoku is not solveable\n");
                        			exit(0);
                    			}
                    			i = pop(&s1);
                   	 		j = pop(&s2);
                    			c = pop(&s3);
                    			goto line;
                		}
            		}
        	}
    	}


}
static void get_elementnine(GtkWidget *widget, gpointer data){
	
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			sudoku[i][j] = atoi(gtk_entry_get_text(GTK_ENTRY(wid[i][j])));
			if(sudoku[i][j] > 9 || sudoku[i][j] < 0){
				for(int i = 0; i < 9; i++){
						for(int j = 0; j < 9; j++){
							sudoku[i][j] = 0;
							gtk_entry_set_text(GTK_ENTRY(wid[i][j]), "0");
						}
					}
					GtkWidget *label;
					window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
					label = gtk_label_new("Sudoku is not solveable");
					g_signal_connect(window, "delete-event", G_CALLBACK(gtk_main_quit), NULL);
					gtk_container_add(GTK_CONTAINER(window), label);
					gtk_widget_show_all(window);
					gtk_main();
					return ;
			}
		}
	}
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			if(sudoku[i][j] != 0){
				if(!insquare(i, j, sudoku[i][j]) && !inrow(i, j, sudoku[i][j]) && !incolumn(i, j, sudoku[i][j])) {

					continue;
				}
				else{
					//printf("Sudoku is not solveable\n");
					//exit(0);
	
					for(int i = 0; i < 9; i++){
						for(int j = 0; j < 9; j++){
							sudoku[i][j] = 0;
							gtk_entry_set_text(GTK_ENTRY(wid[i][j]), "0");
						}
					}
					GtkWidget *label;
					window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
					label = gtk_label_new("Sudoku is not solveable");
					g_signal_connect(window, "delete-event", G_CALLBACK(gtk_main_quit), NULL);
					gtk_container_add(GTK_CONTAINER(window), label);
					gtk_widget_show_all(window);
					gtk_main();
					return ;
				}
			}
		}
	}
	
	solvenine();
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			char c[2];
			sprintf(c, "%d", sudoku[i][j]);
			gtk_entry_set_text(GTK_ENTRY(wid[i][j]), c);
		}
	}					

}
static void get_element16(GtkWidget *widget, gpointer data){
	
	for(int i = 0; i < 16; i++){
		for(int j = 0; j < 16; j++){
			sudoku[i][j] = atoi(gtk_entry_get_text(GTK_ENTRY(wid[i][j])));
			if(sudoku[i][j] > 16 || sudoku[i][j] < 0){
				for(int i = 0; i < 16; i++){
						for(int j = 0; j < 16; j++){
							sudoku[i][j] = 0;
							gtk_entry_set_text(GTK_ENTRY(wid[i][j]), "0");
						}
					}
					GtkWidget *label;
					window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
					label = gtk_label_new("Sudoku is not solveable");
					g_signal_connect(window, "delete-event", G_CALLBACK(gtk_main_quit), NULL);
					gtk_container_add(GTK_CONTAINER(window), label);
					gtk_widget_show_all(window);
					gtk_main();
					return ;
			}
		}
		
		
	}
	for(int i = 0; i < 16; i++){
		for(int j = 0; j < 16; j++){
			if(sudoku[i][j] != 0){
				if(!insquare16(i, j, sudoku[i][j]) && !inrow16(i, j, sudoku[i][j]) && !incolumn16(i, j, sudoku[i][j])) {

					continue;
				}
				else{
					for(int i = 0; i < 16; i++){
						for(int j = 0; j < 16; j++){
							sudoku[i][j] = 0;
							gtk_entry_set_text(GTK_ENTRY(wid[i][j]), "0");
						}
					}
					GtkWidget *label;
					window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
					label = gtk_label_new("Sudoku is not solveable");
					g_signal_connect(window, "delete-event", G_CALLBACK(gtk_main_quit), NULL);
					gtk_container_add(GTK_CONTAINER(window), label);
					gtk_widget_show_all(window);
					gtk_main();
					return ;
				}
			}
		}
	}
	
	solve16();
	for(int i = 0; i < 16; i++){
		for(int j = 0; j < 16; j++){
			char c[2];
			sprintf(c, "%d", sudoku[i][j]);
			gtk_entry_set_text(GTK_ENTRY(wid[i][j]), c);
		}
	}					

}
static void get_element25(GtkWidget *widget, gpointer data){
	
	for(int i = 0; i < 25; i++){
		for(int j = 0; j < 25; j++){
			sudoku[i][j] = atoi(gtk_entry_get_text(GTK_ENTRY(wid[i][j])));
			if(sudoku[i][j] > 25 || sudoku[i][j] < 0){
				for(int i = 0; i < 25; i++){
					for(int j = 0; j < 25; j++){
						sudoku[i][j] = 0;
						gtk_entry_set_text(GTK_ENTRY(wid[i][j]), "0");
					}
				}
				GtkWidget *label;
				window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
				label = gtk_label_new("Sudoku is not solveable");
				g_signal_connect(window, "delete-event", G_CALLBACK(gtk_main_quit), NULL);
				gtk_container_add(GTK_CONTAINER(window), label);
				gtk_widget_show_all(window);
				gtk_main();
				return ;
			}	
		}
	}
	//to check sudoku is solveable or not.
	for(int i = 0; i < 25; i++){
		for(int j = 0; j < 25; j++){
			if(sudoku[i][j] != 0){
				if(!insquare25(i, j, sudoku[i][j]) && !inrow25(i, j, sudoku[i][j]) && !incolumn25(i, j, sudoku[i][j])) {

					continue;
				}
				else{
					
					for(int i = 0; i < 25; i++){
						for(int j = 0; j < 25; j++){
							sudoku[i][j] = 0;
							gtk_entry_set_text(GTK_ENTRY(wid[i][j]), "0");
						}
					}
					GtkWidget *label;
					window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
					label = gtk_label_new("Sudoku is not solveable");
					g_signal_connect(window, "delete-event", G_CALLBACK(gtk_main_quit), NULL);
					gtk_container_add(GTK_CONTAINER(window), label);
					gtk_widget_show_all(window);
					gtk_main();
					return ;
				}
			}
		}
	}
	
	solve25();
	for(int i = 0; i < 25; i++){
		for(int j = 0; j < 25; j++){
			char c[3];
			sprintf(c, "%d", sudoku[i][j]);
			gtk_entry_set_text(GTK_ENTRY(wid[i][j]), c);
		}
	}					

}
void makenine(){
	int a[10], i , j, k = 0, d;
	for(i = 0; i < 9; i++){
		new:
		d = ran() % 10;
		if(d == 0)
			d = 1;
		a[i] = d;
	}
	for(i = 0; i < 9; i++){
        	for(j = 0; j < 9; j++){
        		if(!insquare(i, j, a[k]) && !inrow(i, j, a[k]) && !incolumn(i, j, a[k]) && k < 10) {
        			sudoku[i][j] = a[k];
        			k++;
        		}
        	}
        }
        solvenine();


	for(i = 0; i < 9; i++){
		for(j = 0; j < 9; j++){
			char c[2];
			sprintf(c, "%d", sudoku[i][j]);
			gtk_entry_set_text(GTK_ENTRY(wid[i][j]), c);
		}
	}
}
void make16(){
	int a[16], i , j, k = 0, d;
	for(i = 0; i < 16; i++){
		new:
		d = ran() % 17;
		if(d == 0)
			d = 1;
		a[i] = d;
	}
	for(i = 0; i < 16; i++){
        	for(j = 0; j < 16; j++){
        		if(!insquare16(i, j, a[k]) && !inrow16(i, j, a[k]) && !incolumn16(i, j, a[k]) && k < 16) {
        			sudoku[i][j] = a[k];
        			k++;
        		}
        	}
        }
        solve16();


	for(i = 0; i < 16; i++){
		for(j = 0; j < 16; j++){
			char c[3];
			sprintf(c, "%d", sudoku[i][j]);
			gtk_entry_set_text(GTK_ENTRY(wid[i][j]), c);
		}
	}
}
void make25(){
	int a[25], i , j, k = 0, d;
	for(i = 0; i < 25; i++){
		new:
		d = ran() % 26;
		if(d == 0)
			d = 1;
		a[i] = d;
	}
	for(i = 0; i < 25; i++){
        	for(j = 0; j < 25; j++){
        		if(!insquare25(i, j, a[k]) && !inrow25(i, j, a[k]) && !incolumn25(i, j, a[k]) && k < 25) {
        			sudoku[i][j] = a[k];
        			k++;
        		}
        	}
        }
        solve25();


	for(i = 0; i < 25; i++){
		for(j = 0; j < 25; j++){
			char c[3];
			sprintf(c, "%d", sudoku[i][j]);
			gtk_entry_set_text(GTK_ENTRY(wid[i][j]), c);
		}
	}
}

static void menu_eventnine(GtkWidget *widget, gpointer data){
	if(strcmp(gtk_menu_item_get_label(GTK_MENU_ITEM(widget)), "Make_New") == 0){
		for(int i = 0; i < 9; i++){
			for(int j = 0; j < 9; j++){
				sudoku[i][j] = 0;
				gtk_entry_set_text(GTK_ENTRY(wid[i][j]), "0");
			}
		}
	}
	else if(strcmp(gtk_menu_item_get_label(GTK_MENU_ITEM(widget)), "Easy") == 0){
			int no = 1;
			int a[15];
			for(int i = 0; i < 9; i++){
				for(int j = 0; j < 9; j++){
					sudoku[i][j] = 0;
				}
			}
			makenine();
			int d;
			l:
			d = ran() % 10;
			if(d == 0)
				goto l;
			
			for(int i = 0; i < 9; i++){
				for(int j = 0; j < 9; j++){ 			
					int sm =  i * 9 + j + 1;
					if(sm % d == 0 && no <= 15){
						no++;
						gtk_entry_set_text(GTK_ENTRY(wid[i][j]), "0");
					}			
					else{
						char c[2];
						sprintf(c, "%d", sudoku[i][j]);			
						gtk_entry_set_text(GTK_ENTRY(wid[i][j]), c);
					}		
				}				
			}
					
		
	}
	else if(strcmp(gtk_menu_item_get_label(GTK_MENU_ITEM(widget)), "Medium") == 0){
			int no = 1;
			int a[35];
			for(int i = 0; i < 9; i++){
				for(int j = 0; j < 9; j++){
					sudoku[i][j] = 0;
				}
			}
			makenine();
			int d;
			m:
			d = ran() % 6;
			if(d == 0)
				goto m;
			
			for(int i = 0; i < 9; i++){
				for(int j = 0; j < 9; j++){ 			
					int sm =  i * 9 + j + 1;
					if(sm % d == 0 && no <= 35){
						no++;
						gtk_entry_set_text(GTK_ENTRY(wid[i][j]), "0");	
					}		
					else{
						char c[2];
						sprintf(c, "%d", sudoku[i][j]);			
						gtk_entry_set_text(GTK_ENTRY(wid[i][j]), c);
					}		
				}				
			}
					
		
	}
	else if(strcmp(gtk_menu_item_get_label(GTK_MENU_ITEM(widget)), "Difficult") == 0){
			int no = 1;
			int a[50];
			for(int i = 0; i < 9; i++){
				for(int j = 0; j < 9; j++){
					sudoku[i][j] = 0;
				}
			}
			makenine();
			int d;
			ns:
			d = ran() % 4;
			if(d == 0)
				goto ns;
			
			for(int i = 0; i < 9; i++){
				for(int j = 0; j < 9; j++){ 			
					int sm =  i * 9 + j + 1;
					if(sm % d == 0 && no <= 50){
						no++;
						gtk_entry_set_text(GTK_ENTRY(wid[i][j]), "0");	
					}		
					else{
						char c[2];
						sprintf(c, "%d", sudoku[i][j]);			
						gtk_entry_set_text(GTK_ENTRY(wid[i][j]), c);
					}		
				}				
			}
					
		
	}
	else if(strcmp(gtk_menu_item_get_label(GTK_MENU_ITEM(widget)), "Hint") == 0){
		int d;
		for(int i = 0; i < 9; i++){
			for(int j = 0; j < 9; j++){
				d = atoi(gtk_entry_get_text(GTK_ENTRY(wid[i][j])));
				if(d == 0){
					char c[2];
					sprintf(c, "%d", sudoku[i][j]);			
					gtk_entry_set_text(GTK_ENTRY(wid[i][j]), c);
					return;
				}
			}
		}
					
	}
	else if(strcmp(gtk_menu_item_get_label(GTK_MENU_ITEM(widget)), "Resume") == 0){
		int fd ,i = 0, l, m, d = 0;
		char ch, a[3];
		fd = open("sudoku.txt", O_RDWR, S_IRUSR | S_IWUSR);
		if(fd == -1){
			printf("File is not opened\n");
			exit(0);
		}
		while(read(fd, &ch, 1)){
			if(ch >= 48 && ch <= 57){
				a[i++] = ch;
			}
			else{
				a[i] = '\0';
				i = 0;
				d++;
				if(d % 9 == 0){
					l = d / 9 - 1;
					m = 8;
				}
				else{
					l = d / 9;
					m = d % 9 - 1;
				}
				gtk_entry_set_text(GTK_ENTRY(wid[l][m]), a);
				sudoku[l][m] = atoi(a);
			}
		}
		solvenine();
	}
	else if(strcmp(gtk_menu_item_get_label(GTK_MENU_ITEM(widget)), "Exit") == 0){
		int i, j, noz = 0, gi;
		for(i = 0; i < 9; i++){
			for(j = 0; j < 9; j++){
				if(!atoi(gtk_entry_get_text(wid[i][j])))
					noz++;
			}
		}
		if(noz > 0){
			int fd ,i = 0, l, m, d = 0;
			char ch = ' ', a[3];
			fd = open("sudoku.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
			if(fd == -1){
				printf("File is not opened\n");
				exit(0);
			}
			for(i = 0; i < 9; i++){
				for(j = 0; j < 9; j++){
					//strcpy(a, gtk_entry_get_text(wid[i][j]));
					gi = atoi(gtk_entry_get_text(wid[i][j]));
					sprintf(a, "%d", gi);
					write(fd, a, 1);
					write(fd, &ch, 1);
				}
			}
		}
		gtk_main_quit();
	}
}
static void menu_event16(GtkWidget *widget, gpointer data){
	if(strcmp(gtk_menu_item_get_label(GTK_MENU_ITEM(widget)), "Make_New") == 0){
		for(int i = 0; i < 16; i++){
			for(int j = 0; j < 16; j++){
				sudoku[i][j] = 0;
				gtk_entry_set_text(GTK_ENTRY(wid[i][j]), "0");
			}
		}
	}
	else if(strcmp(gtk_menu_item_get_label(GTK_MENU_ITEM(widget)), "Easy") == 0){
			int no = 1;
			int a[50];
			for(int i = 0; i < 16; i++){
				for(int j = 0; j < 16; j++){
					sudoku[i][j] = 0;
				}
			}
			make16();
			int d;
			l:
			d = ran() % 17;
			if(d == 0)
				goto l;
			
			for(int i = 0; i < 16; i++){
				for(int j = 0; j < 16; j++){ 			
					int sm =  i * 16 + j + 1;
					if(sm % d == 0 && no <= 40){
						no++;
						gtk_entry_set_text(GTK_ENTRY(wid[i][j]), "0");
					}			
					else{
						char c[3];
						sprintf(c, "%d", sudoku[i][j]);			
						gtk_entry_set_text(GTK_ENTRY(wid[i][j]), c);
					}		
				}				
			}
					
		
	}
	else if(strcmp(gtk_menu_item_get_label(GTK_MENU_ITEM(widget)), "Medium") == 0){
			int no = 1;
			int a[100];
			for(int i = 0; i < 16; i++){
				for(int j = 0; j < 16; j++){
					sudoku[i][j] = 0;
				}
			}
			make16();
			int d;
			m:
			d = ran() % 10;
			if(d == 0)
				goto m;
			
			for(int i = 0; i < 16; i++){
				for(int j = 0; j < 16; j++){ 			
					int sm =  i * 16 + j + 1;
					if(sm % d == 0 && no <= 70){
						no++;
						gtk_entry_set_text(GTK_ENTRY(wid[i][j]), "0");	
					}		
					else{
						char c[3];
						sprintf(c, "%d", sudoku[i][j]);			
						gtk_entry_set_text(GTK_ENTRY(wid[i][j]), c);
					}		
				}				
			}
					
		
	}
	else if(strcmp(gtk_menu_item_get_label(GTK_MENU_ITEM(widget)), "Difficult") == 0){
			int no = 1;
			int a[175];
			for(int i = 0; i < 16; i++){
				for(int j = 0; j < 16; j++){
					sudoku[i][j] = 0;
				}
			}
			make16();
			int d;
			ns:
			d = ran() % 6;
			if(d == 0)
				goto ns;
			
			for(int i = 0; i < 16; i++){
				for(int j = 0; j < 16; j++){ 			
					int sm =  i * 16 + j + 1;
					if(sm % d == 0 && no <= 125){
						no++;
						gtk_entry_set_text(GTK_ENTRY(wid[i][j]), "0");	
					}		
					else{
						char c[3];
						sprintf(c, "%d", sudoku[i][j]);			
						gtk_entry_set_text(GTK_ENTRY(wid[i][j]), c);
					}		
				}				
			}
					
		
	}
	else if(strcmp(gtk_menu_item_get_label(GTK_MENU_ITEM(widget)), "Hint") == 0){
		int d;
		for(int i = 0; i < 16; i++){
			for(int j = 0; j < 16; j++){
				d = atoi(gtk_entry_get_text(GTK_ENTRY(wid[i][j])));
				if(d == 0){
					char c[3];
					sprintf(c, "%d", sudoku[i][j]);			
					gtk_entry_set_text(GTK_ENTRY(wid[i][j]), c);
					return;
				}
			}
		}
					
	}
	else if(strcmp(gtk_menu_item_get_label(GTK_MENU_ITEM(widget)), "Resume") == 0){
		int fd ,i = 0, l, m, d = 0;
		char ch, a[3];
		fd = open("sudoku16.txt", O_RDWR, S_IRUSR | S_IWUSR);
		if(fd == -1){
			printf("File is not available\n");
			exit(0);
		}
		while(read(fd, &ch, 1)){
			if(ch >= 48 && ch <= 57){
				a[i++] = ch;
			}
			else{
				a[i] = '\0';
				i = 0;
				d++;
				if(d % 16 == 0){
					l = d /16  - 1;
					m = 15;
				}
				else{
					l = d / 16;
					m = d % 16 - 1;
				}
				gtk_entry_set_text(GTK_ENTRY(wid[l][m]), a);
				sudoku[l][m] = atoi(a);
			}
		}
		solve16();
	}
	else if(strcmp(gtk_menu_item_get_label(GTK_MENU_ITEM(widget)), "Exit") == 0){
		int i, j, noz = 0, gi;
		for(i = 0; i < 16; i++){
			for(j = 0; j < 16; j++){
				if(!atoi(gtk_entry_get_text(wid[i][j])))
					noz++;
			}
		}
		if(noz > 0){
			int fd ,i = 0, l, m, d = 0, gi;
			char ch = ' ', a[3];
			fd = open("sudoku16.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
			if(fd == -1){
				printf("File is not opened\n");
				exit(0);
			}
			//gchar **endptr = NULL;
			//guint base;
			for(i = 0; i < 16; i++){
				for(j = 0; j < 16; j++){
					//strcpy(a, gtk_entry_get_text(wid[i][j]));
					//gi = g_ascii_strtoll(gtk_entry_get_text(wid[i][j]), **endptr, base);
					//sprintf(a, "%d", gi);
					gi = atoi(gtk_entry_get_text(wid[i][j]));
					sprintf(a, "%d", gi);
					write(fd, a, 2);
					write(fd, &ch, 1);
				}
			
			}
		}
		gtk_main_quit();
		
	}
}
static void menu_event25(GtkWidget *widget, gpointer data){
	if(strcmp(gtk_menu_item_get_label(GTK_MENU_ITEM(widget)), "Make_New") == 0){
		for(int i = 0; i < 25; i++){
			for(int j = 0; j < 25; j++){
				sudoku[i][j] = 0;
				gtk_entry_set_text(GTK_ENTRY(wid[i][j]), "0");
			}
		}
	}
	else if(strcmp(gtk_menu_item_get_label(GTK_MENU_ITEM(widget)), "Easy") == 0){
			int no = 1;
			int a[100];
			for(int i = 0; i < 25; i++){
				for(int j = 0; j < 25; j++){
					sudoku[i][j] = 0;
				}
			}
			make25();
			int d;
			
			d = ran() % 26;
			if(d == 0)
				d = 3;
			
			for(int i = 0; i < 25; i++){
				for(int j = 0; j < 25; j++){ 			
					int sm =  i * 25 + j + 1;
					if(sm % d == 0 && no <= 100){
						no++;
						gtk_entry_set_text(GTK_ENTRY(wid[i][j]), "0");
					}			
					else{
						char c[3];
						sprintf(c, "%d", sudoku[i][j]);			
						gtk_entry_set_text(GTK_ENTRY(wid[i][j]), c);
					}		
				}				
			}
					
		
	}
	else if(strcmp(gtk_menu_item_get_label(GTK_MENU_ITEM(widget)), "Medium") == 0){
			int no = 1;
			int a[250];
			for(int i = 0; i < 25; i++){
				for(int j = 0; j < 25; j++){
					sudoku[i][j] = 0;
				}
			}
			make25();
			int d;
			d = ran() % 18;
			if(d == 0)
				d = 3;
			
			for(int i = 0; i < 25; i++){
				for(int j = 0; j < 25; j++){ 			
					int sm =  i * 25 + j + 1;
					if(sm % d == 0 && no <= 200){
						no++;
						gtk_entry_set_text(GTK_ENTRY(wid[i][j]), "0");	
					}		
					else{
						char c[3];
						sprintf(c, "%d", sudoku[i][j]);			
						gtk_entry_set_text(GTK_ENTRY(wid[i][j]), c);
					}		
				}				
			}
					
		
	}
	else if(strcmp(gtk_menu_item_get_label(GTK_MENU_ITEM(widget)), "Difficult") == 0){
			int no = 1;
			int a[500];
			for(int i = 0; i < 25; i++){
				for(int j = 0; j < 25; j++){
					sudoku[i][j] = 0;
				}
			}
			make25();
			int d;
			d = ran() % 10;
			if(d == 0)
				d = 3;
			
			for(int i = 0; i < 25; i++){
				for(int j = 0; j < 25; j++){ 			
					int sm =  i * 25 + j + 1;
					if(sm % d == 0 && no <= 450){
						no++;
						gtk_entry_set_text(GTK_ENTRY(wid[i][j]), "0");	
					}		
					else{
						char c[3];
						sprintf(c, "%d", sudoku[i][j]);			
						gtk_entry_set_text(GTK_ENTRY(wid[i][j]), c);
					}		
				}				
			}
					
		
	}
	else if(strcmp(gtk_menu_item_get_label(GTK_MENU_ITEM(widget)), "Hint") == 0){
		int d;
		for(int i = 0; i < 25; i++){
			for(int j = 0; j < 25; j++){
				d = atoi(gtk_entry_get_text(GTK_ENTRY(wid[i][j])));
				if(d == 0){
					char c[3];
					sprintf(c, "%d", sudoku[i][j]);			
					gtk_entry_set_text(GTK_ENTRY(wid[i][j]), c);
					return;
				}
			}
		}
					
	}
	else if(strcmp(gtk_menu_item_get_label(GTK_MENU_ITEM(widget)), "Resume") == 0){
		int fd ,i = 0, l, m, d = 0;
		char ch, a[3];
		fd = open("sudoku25.txt", O_RDWR, S_IRUSR | S_IWUSR);
		if(fd == -1){
			printf("File is not opened\n");
			exit(0);
		}
		while(read(fd, &ch, 1)){
			if(ch >= 48 && ch <= 57){
				a[i++] = ch;
			}
			else{
				a[i] = '\0';
				i = 0;
				d++;
				if(d % 25 == 0){
					l = d / 25 - 1;
					m = 24;
				}
				else{
					l = d / 25;
					m = d % 25 - 1;
				}
				gtk_entry_set_text(GTK_ENTRY(wid[l][m]), a);
				sudoku[l][m] = atoi(a);
			}
		}
		solve25();
	}
	else if(strcmp(gtk_menu_item_get_label(GTK_MENU_ITEM(widget)), "Exit") == 0){
		int i, j, noz = 0, d, n;
		for(i = 0; i < 25; i++){
			for(j = 0; j < 25; j++){
				if((n = atoi(gtk_entry_get_text(wid[i][j]))))
					noz++;
			}
		}
		if(noz > 0){
			int fd ,i = 0, l, m, d = 0;
			char ch = ' ', *a = (char *)malloc(sizeof(char) * 3);;
			fd = open("sudoku25.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
			if(fd == -1){
				printf("File is not opened\n");
				exit(0);
			}
			for(i = 0; i < 25; i++){
				for(j = 0; j < 25; j++){
					strcpy(a, gtk_entry_get_text(wid[i][j]));
					write(fd, a, 3);
					write(fd, &ch, 1);
				}
			}
		}
		gtk_main_quit();
	}
}
static void menu_event(GtkWidget *widget, gpointer data){
	if(strcmp(gtk_menu_item_get_label(GTK_MENU_ITEM(widget)), "9") == 0){
		const char* file[] = {"Make_New", "Exit"};
		const char* new[] = {"Easy", "Medium", "Difficult"};
		const char* hint[] = {"Hint"};
		const char* resume[] = {"Resume"};
		for(int i = 0; i < 9; i++)
			for(int j = 0; j < 9; j++)
				sudoku[i][j] = 0;
		GtkWidget *vbox, *hbox, *separator, *button, *file_menu, *solve_menu, *hint_menu, *resume_menu, *menu_bar, *menu_item;
		window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
		vbox = gtk_vbox_new(0, 0);
		gtk_widget_set_size_request(vbox, 5, 5);
		file_menu = gtk_menu_new();
		solve_menu = gtk_menu_new();
		hint_menu = gtk_menu_new();
		resume_menu = gtk_menu_new();
		menu_bar = gtk_menu_bar_new();
		menu_item = gtk_menu_item_new_with_label("File");
		gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_item),file_menu);
		gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), menu_item);
		menu_item = gtk_menu_item_new_with_label("Resume");
		gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_item),resume_menu);
		gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), menu_item);
		menu_item = gtk_menu_item_new_with_label("New_Game");
		gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_item),solve_menu);
		gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), menu_item);
		menu_item = gtk_menu_item_new_with_label("Hint");
		gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_item),hint_menu);
		gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), menu_item);
		menu_item = gtk_menu_item_new_with_label(resume[0]);
		gtk_menu_shell_append(GTK_MENU_SHELL(resume_menu), menu_item);
		g_signal_connect(menu_item, "activate", G_CALLBACK(menu_eventnine), NULL);
		menu_item = gtk_menu_item_new_with_label(hint[0]);
		gtk_menu_shell_append(GTK_MENU_SHELL(hint_menu), menu_item);
		g_signal_connect(menu_item, "activate", G_CALLBACK(menu_eventnine), NULL);
		for(int i = 0; i < 3; i++){
			menu_item = gtk_menu_item_new_with_label(new[i]);
			gtk_menu_shell_append(GTK_MENU_SHELL(solve_menu), menu_item);
			g_signal_connect(menu_item, "activate", G_CALLBACK(menu_eventnine), NULL);
		}
		for(int i = 0; i < 2; i++){
			menu_item = gtk_menu_item_new_with_label(file[i]);
			gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), menu_item);
			g_signal_connect(menu_item, "activate", G_CALLBACK(menu_eventnine), NULL);
		}
		gtk_box_pack_start(GTK_BOX(vbox), menu_bar, 0, 0, 0);
		
		for(int i = 0; i < 9; i++){
	    		hbox = gtk_hbox_new(0, 0);
	    		gtk_widget_set_size_request(hbox, 5, 5);
	    		for(int j = 0; j < 9; j++){
	    			wid[i][j] = gtk_entry_new();
	    			gtk_entry_set_max_length(GTK_ENTRY(wid[i][j]), 2);
	    			gtk_box_pack_start(GTK_BOX(hbox), wid[i][j], 0, 0, 0);
	    			if((j + 1) % 3 == 0){
	    				separator = gtk_vseparator_new();
	    				gtk_box_pack_start(GTK_BOX(hbox), separator, 0, 0, 0);
	    				gtk_widget_set_size_request(separator, 10, 5);
	    			}
	    	}
	    gtk_box_pack_start(GTK_BOX(vbox), hbox, 0, 0, 0);
		if((i + 1) % 3 == 0){
	    		separator = gtk_hseparator_new();
	    		gtk_box_pack_start(GTK_BOX(vbox), separator, 0, 0, 0);
	    		gtk_widget_set_size_request(separator, 15, 5);
	    	}
	}
	button = gtk_button_new_with_label("Solve the sudoku");
	g_signal_connect(button, "clicked", G_CALLBACK(get_elementnine), NULL);
	gtk_box_pack_start(GTK_BOX(vbox), button, 0, 0, 0);
	g_signal_connect(window, "delete-event", G_CALLBACK(gtk_main_quit), NULL);
	gtk_window_set_default_size(GTK_WINDOW(window), 45, 45);
	gtk_container_add(GTK_CONTAINER(window), vbox);
    	gtk_widget_show_all(window);
    	gtk_main();
    	return ;
	}
	else if(strcmp(gtk_menu_item_get_label(GTK_MENU_ITEM(widget)), "16") == 0){
		const char* file[] = {"Make_New", "Exit"};
		const char* new[] = {"Easy", "Medium", "Difficult"};
		const char* hint[] = {"Hint"};
		const char* resume[] = {"Resume"};
		for(int i = 0; i < 16; i++)
			for(int j = 0; j < 16; j++)
				sudoku[i][j] = 0;
		GtkWidget *vbox, *hbox, *separator, *button, *file_menu, *solve_menu, *hint_menu, *menu_bar, *resume_menu, *menu_item;
		window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
		vbox = gtk_vbox_new(0, 0);
		file_menu = gtk_menu_new();
		solve_menu = gtk_menu_new();
		resume_menu = gtk_menu_new();
		hint_menu = gtk_menu_new();
		menu_bar = gtk_menu_bar_new();
		menu_item = gtk_menu_item_new_with_label("File");
		gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_item),file_menu);
		gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), menu_item);
		menu_item = gtk_menu_item_new_with_label("Resume");
		gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_item),resume_menu);
		gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), menu_item);
		menu_item = gtk_menu_item_new_with_label("Hint");
		gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_item),hint_menu);
		gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), menu_item);
		menu_item = gtk_menu_item_new_with_label("New_Game");
		gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_item),solve_menu);
		gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), menu_item);
		menu_item = gtk_menu_item_new_with_label(resume[0]);
		gtk_menu_shell_append(GTK_MENU_SHELL(resume_menu), menu_item);
		g_signal_connect(menu_item, "activate", G_CALLBACK(menu_event16), NULL);
		menu_item = gtk_menu_item_new_with_label(hint[0]);
		gtk_menu_shell_append(GTK_MENU_SHELL(hint_menu), menu_item);
		g_signal_connect(menu_item, "activate", G_CALLBACK(menu_event16), NULL);
		for(int i = 0; i < 3; i++){
			menu_item = gtk_menu_item_new_with_label(new[i]);
			gtk_menu_shell_append(GTK_MENU_SHELL(solve_menu), menu_item);
			g_signal_connect(menu_item, "activate", G_CALLBACK(menu_event16), NULL);
		}
		for(int i = 0; i < 2; i++){
			menu_item = gtk_menu_item_new_with_label(file[i]);
			gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), menu_item);
			g_signal_connect(menu_item, "activate", G_CALLBACK(menu_event16), NULL);
		}
		gtk_box_pack_start(GTK_BOX(vbox), menu_bar, 0, 0, 0);
		
		for(int i = 0; i < 16; i++){
	    		hbox = gtk_hbox_new(0, 0);
	    		for(int j = 0; j < 16; j++){
	    			wid[i][j] = gtk_entry_new();
	    			gtk_entry_set_max_length(GTK_ENTRY(wid[i][j]), 3);
	    			gtk_box_pack_start(GTK_BOX(hbox), wid[i][j], 0, 0, 0);
	    			if((j + 1) % 4 == 0){
	    				separator = gtk_vseparator_new();
	    				gtk_box_pack_start(GTK_BOX(hbox), separator, 0, 0, 0);
	    			}
	    	}
	    gtk_box_pack_start(GTK_BOX(vbox), hbox, 0, 0, 0);
		if((i + 1) % 4 == 0){
	    		separator = gtk_hseparator_new();
	    		gtk_box_pack_start(GTK_BOX(vbox), separator, 0, 0, 0);
	    	}
	}
	button = gtk_button_new_with_label("Solve the sudoku");
	g_signal_connect(button, "clicked", G_CALLBACK(get_element16), NULL);
	gtk_box_pack_start(GTK_BOX(vbox), button, 0, 0, 0);
	g_signal_connect(window, "delete-event", G_CALLBACK(gtk_main_quit), NULL);
	gtk_window_resize(GTK_WINDOW(window), 400, 300);
	gtk_container_add(GTK_CONTAINER(window), vbox);
    	gtk_widget_show_all(window);
    	gtk_main();
    	return ;
	}
	else if(strcmp(gtk_menu_item_get_label(GTK_MENU_ITEM(widget)), "25") == 0){
		const char* file[] = {"Make_New", "Exit"};
		const char* new[] = {"Easy", "Medium", "Difficult"};
		const char* hint[] = {"Hint"};
		const char* resume[] = {"Resume"};
		for(int i = 0; i < 25; i++)
			for(int j = 0; j < 25; j++)
				sudoku[i][j] = 0;
		GtkWidget *vbox, *hbox, *separator, *button, *file_menu, *solve_menu, *hint_menu, *resume_menu, *menu_bar, *menu_item;
		window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
		vbox = gtk_vbox_new(0, 0);
		file_menu = gtk_menu_new();
		solve_menu = gtk_menu_new();
		resume_menu = gtk_menu_new();
		hint_menu = gtk_menu_new();
		menu_bar = gtk_menu_bar_new();
		menu_item = gtk_menu_item_new_with_label("File");
		gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_item),file_menu);
		gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), menu_item);
		menu_item = gtk_menu_item_new_with_label("Resume");
		gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_item),resume_menu);
		gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), menu_item);
		menu_item = gtk_menu_item_new_with_label("Hint");
		gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_item),hint_menu);
		gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), menu_item);
		menu_item = gtk_menu_item_new_with_label("New_Game");
		gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_item),solve_menu);
		gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), menu_item);
		menu_item = gtk_menu_item_new_with_label(resume[0]);
		gtk_menu_shell_append(GTK_MENU_SHELL(resume_menu), menu_item);
		g_signal_connect(menu_item, "activate", G_CALLBACK(menu_event25), NULL);
		menu_item = gtk_menu_item_new_with_label(hint[0]);
		gtk_menu_shell_append(GTK_MENU_SHELL(hint_menu), menu_item);
		g_signal_connect(menu_item, "activate", G_CALLBACK(menu_event25), NULL);
		for(int i = 0; i < 3; i++){
			menu_item = gtk_menu_item_new_with_label(new[i]);
			gtk_menu_shell_append(GTK_MENU_SHELL(solve_menu), menu_item);
			g_signal_connect(menu_item, "activate", G_CALLBACK(menu_event25), NULL);
		}
		for(int i = 0; i < 2; i++){
			menu_item = gtk_menu_item_new_with_label(file[i]);
			gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), menu_item);
			g_signal_connect(menu_item, "activate", G_CALLBACK(menu_event25), NULL);
		}
		gtk_box_pack_start(GTK_BOX(vbox), menu_bar, 0, 0, 0);
		
		for(int i = 0; i < 25; i++){
	    		hbox = gtk_hbox_new(0, 0);
	    		for(int j = 0; j < 25; j++){
	    			wid[i][j] = gtk_entry_new();
	    			gtk_entry_set_max_length(GTK_ENTRY(wid[i][j]), 3);
	    			gtk_box_pack_start(GTK_BOX(hbox), wid[i][j], 0, 0, 0);
	    			if((j + 1) % 5 == 0){
	    				separator = gtk_vseparator_new();
	    				gtk_box_pack_start(GTK_BOX(hbox), separator, 0, 0, 0);
	    			}
	    	}
	    gtk_box_pack_start(GTK_BOX(vbox), hbox, 0, 0, 0);
		if((i + 1) % 5 == 0){
	    		separator = gtk_hseparator_new();
	    		gtk_box_pack_start(GTK_BOX(vbox), separator, 0, 0, 0);
	    	}
	}
	button = gtk_button_new_with_label("Solve the sudoku");
	g_signal_connect(button, "clicked", G_CALLBACK(get_element25), NULL);
	gtk_box_pack_start(GTK_BOX(vbox), button, 0, 0, 0);
	g_signal_connect(window, "delete-event", G_CALLBACK(gtk_main_quit), NULL);
	gtk_window_resize(GTK_WINDOW(window), 400, 300);
	gtk_container_add(GTK_CONTAINER(window), vbox);
    	gtk_widget_show_all(window);
    	gtk_main();
    	return ;
	}
}
int main(int argc, char *argv[]){
	const char *size[] ={"9", "16", "25"};
	gtk_init(&argc, &argv);
	GtkWidget *vbox, *hbox, *separator, *button, *size_menu, *menu_bar, *menu_item;
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	menu_bar = gtk_menu_bar_new();
	vbox = gtk_vbox_new(0, 0);
	size_menu = gtk_menu_new();
	menu_item = gtk_menu_item_new_with_label("Size");
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_item),size_menu);
	gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), menu_item);
	g_signal_connect(menu_item, "activate", G_CALLBACK(menu_event), NULL);
	for(int i = 0; i < 3; i++){
		menu_item = gtk_menu_item_new_with_label(size[i]);
		gtk_menu_shell_append(GTK_MENU_SHELL(size_menu), menu_item);
		g_signal_connect(menu_item, "activate", G_CALLBACK(menu_event), NULL);
	}
	gtk_box_pack_start(GTK_BOX(vbox), menu_bar, 0, 0, 0);
	g_signal_connect(window, "delete-event", G_CALLBACK(gtk_main_quit), NULL);
	gtk_window_resize(GTK_WINDOW(window), 200, 200);
	gtk_container_add(GTK_CONTAINER(window), vbox);
	gtk_widget_show_all(window);
	gtk_main();
	return 0;
}
