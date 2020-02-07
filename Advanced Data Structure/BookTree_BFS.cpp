/*
MET BKC IOE, NASHIK
-ADS-Creating A Book Binary Tree Containing Name, Chapters, Sections And Subsections.
-ROLL No. 02
-SE.B Comp
-TEXT EDITOR
*/

#include <iostream>

#include <stdlib.h>

#include <string.h>

using namespace std;

struct node {
  char name[20];
  node * next;
  node * down;
  int flag;
};

class Book_Tree {
  char ch[20];
  int n, i;
  node * head = NULL, * temp = NULL, * t1 = NULL, * t2 = NULL,* t3 = NULL;

  public:
    node * create();

  void insert_book();
  void insert_chapter();
  void insert_section();
  void insert_sub_section();
  void display_book();
  void bfs_book();
};
node * Book_Tree::create() {

  node * p = new(struct node);

  p -> next = NULL;
  p -> down = NULL;
  p -> flag = 0;
  cout << "\n enter the name";
  cin >> p -> name;
  return p;
}

void Book_Tree::insert_book() {

  if (head == NULL) {
    t1 = create();
    head = t1;
  } else {
    cout << "\n book exist";
  }
}
void Book_Tree::insert_chapter() {
  if (head == NULL) {
    cout << "\n there is no book";
  } else {
    cout << "\n how many chapters you want to insert";
    cin >> n;
    for (i = 0; i < n; i++) {
      t1 = create();
      if (head -> flag == 0) {
        head -> down = t1;
        head -> flag = 1;
      } else {
        temp = head;
        temp = temp -> down;
        while (temp -> next != NULL)
          temp = temp -> next;
        temp -> next = t1;
      }
    }
  }
}
void Book_Tree::insert_section() {

  if (head == NULL) {
    cout << "\n there is no book";
  } else {
    cout << "\n Enter the name of chapter on which  you want to enter the section";
    cin >> ch;

    temp = head;
    if (temp -> flag == 0) {
      cout << "\n their are no chapters on in book";
    } else {
      temp = temp -> down;
      while (temp != NULL) {
        if (!strcmp(ch, temp -> name)) {
          cout << "\n how many sections you want to enter";
          cin >> n;
          for (i = 0; i < n; i++) {

            t1 = create();
            if (temp -> flag == 0) {
              temp -> down = t1;

              temp -> flag = 1;
              cout << "\n******";
              t2 = temp -> down;
            } else {
              cout << "\n#####";
              while (t2 -> next != NULL) {
                t2 = t2 -> next;
              }
              t2 -> next = t1;
            }
          }
          break;
        }
        temp = temp -> next;
      }
    }
  }
}
void Book_Tree::insert_sub_section() {

  if (head == NULL) {
    cout << "\n there is no book";
  } else {
    cout << "\n Enter the name of chapter on which  you want to enter the section";
    cin >> ch;

    temp = head;
    if (temp -> flag == 0) {
      cout << "\n their are no chapters on in book";
    } else {
      temp = temp -> down;
      while (temp != NULL) {
        if (!strcmp(ch, temp -> name)) {
          cout << "\n enter name of section in which you want to enter the sub section";
          cin >> ch;

          if (temp -> flag == 0) {
            cout << "\n their are no sections ";
          } else {
            temp = temp -> down;
            while (temp != NULL) {
              if (!strcmp(ch, temp -> name)) {
                cout << "\n how many subsections you want to enter";
                cin >> n;
                for (i = 0; i < n; i++) {

                  t1 = create();
                  if (temp -> flag == 0) {
                    temp -> down = t1;

                    temp -> flag = 1;
                    cout << "\n******";
                    t2 = temp -> down;
                  } else {
                    cout << "\n#####";
                    while (t2 -> next != NULL) {
                      t2 = t2 -> next;
                    }
                    t2 -> next = t1;
                  }
                }
                break;
              }
              temp = temp -> next;
            }
          }
        }

        temp = temp -> next;
      }
    }
  }
}
void Book_Tree::display_book() {

  if (head == NULL) {
    cout << "\n there is no book";
  } else {
    cout << "\n\n Book - " << head -> name;
    temp = head; //for title
    if (temp -> flag) {
      temp = temp -> down;

      while (temp != NULL) {
        cout << "\n\n Chapter - ";
        cout << "\n\t\t" << temp -> name; // for chapters
        t1 = temp;
        if (temp -> flag) {
          t1 = t1 -> down;

          while (t1 != NULL) {
            cout << "\n\t\t\t Section - ";
            cout << "\t" << t1 -> name; // for section

            t2 = t1;
            if (t1 -> flag) {
              t2 = t2 -> down;

              while (t2 != NULL) {
                cout << "\n\t\t\t\t SubSection - ";
                cout << "\t" << t2 -> name; // for section
                t2 = t2 -> next;
              }
            }
            t1 = t1 -> next;
          }
        }
        temp = temp -> next;
      }
    }
  }
}

void Book_Tree::bfs_book() {

  if (head == NULL) {
    cout << "\n there is no book";
  } else {
	  ///////////
    cout << head -> name << endl;
	
	
    temp = head; //for title
    if (temp -> flag) {
      t1 = temp -> down;
      while (t1 != NULL) {
        cout << "\t" << t1 -> name;
        t1 = t1 -> next;
      }
    }
	///////////////
	    cout << "\n";

	temp = head; //for title
    if (temp -> flag) {
      t1 = temp -> down;
      while (t1 != NULL) {
		if (t1 -> flag) {  
			t2 = t1 -> down; //for title
			while(t2 != NULL) {
			    cout << "\t" << t2 -> name;
				t2 = t2 ->next  ;
			}
		}
		t1 = t1 ->next;
	  }
	}
	
	
	    cout << "\n";

	temp = head; //for title
    if (temp -> flag) {
      t1 = temp -> down;
      while (t1 != NULL) {
		if (t1 -> flag) {  
			t2 = t1 -> down; //for title
			while(t2 != NULL) {
				t3 = t2 -> down;
				 //for title
					while(t3 != NULL) {
						cout << "\t" << t3 -> name;
						t3 = t3 ->next  ;
					}
				t2 = t2 ->next;
				}
				
			}
		t1 = t1 ->next;
		}
		
	  }
	}
}
int main() {
  Book_Tree bt_object;
  int x;
  while (1) {
    cout << "\n\n enter your choice";
    cout << "\n 1.insert book";
    cout << "\n 2.insert chapter";
    cout << "\n 3.insert section";
    cout << "\n 4.insert subsection";
    cout << "\n 5.display book";
    cout << "\n 6.display book BFS";
    cout << "\n 7.exit";
    cin >> x;
    switch (x) {
    case 1:
      bt_object.insert_book();
      break;
    case 2:
      bt_object.insert_chapter();
      break;
    case 3:
      bt_object.insert_section();
      break;
    case 4:
      bt_object.insert_sub_section();
      break;
    case 5:
      bt_object.display_book();
      break;
	case 6:
	  bt_object.bfs_book();
      break;
    case 7:
      exit(0);
    }
  }
  return 0;
}

//OUTPUT - 
/*

 enter your choice
 1.insert book
 2.insert chapter
 3.insert section
 4.insert subsection
 5.display book
 6.display book BFS
 7.exit1

 enter the nameADS


 enter your choice
 1.insert book
 2.insert chapter
 3.insert section
 4.insert subsection
 5.display book
 6.display book BFS
 7.exit2

 how many chapters you want to insert2

 enter the nameAAA BBB

 enter the name

 enter your choice
 1.insert book
 2.insert chapter
 3.insert section
 4.insert subsection
 5.display book
 6.display book BFS
 7.exit3

 Enter the name of chapter on which  you want to enter the sectionAAA

 how many sections you want to enter1

 enter the nameCCC

******
 enter your choice
 1.insert book
 2.insert chapter
 3.insert section
 4.insert subsection
 5.display book
 6.display book BFS
 7.exit1

 enter the nameADS


 enter your choice
 1.insert book
 2.insert chapter
 3.insert section
 4.insert subsection
 5.display book
 6.display book BFS
 7.exit2

 how many chapters you want to insert2

 enter the nameAAA BBB

 enter the name

 enter your choice
 1.insert book
 2.insert chapter
 3.insert section
 4.insert subsection
 5.display book
 6.display book BFS
 7.exit3

 Enter the name of chapter on which  you want to enter the sectionAAA

 how many sections you want to enter1

 enter the nameCCC

******

 enter your choice
 1.insert book
 2.insert chapter
 3.insert section
 4.insert subsection
 5.display book
 6.display book BFS
 7.exit3

 Enter the name of chapter on which  you want to enter the sectionBBB

 how many sections you want to enter2

 enter the nameJJJ KKK

******
 enter the name
#####

 enter your choice
 1.insert book
 2.insert chapter
 3.insert section
 4.insert subsection
 5.display book
 6.display book BFS
 7.exit4

 Enter the name of chapter on which  you want to enter the sectionBBB

 enter name of section in which you want to enter the sub sectionKKK

 how many subsections you want to enter3

 enter the nameLLL MMM NNN

******
 enter the name
#####
 enter the name
#####

 enter your choice
 1.insert book
 2.insert chapter
 3.insert section
 4.insert subsection
 5.display book
 6.display book BFS
 7.exit5


 Book - ADS

 Chapter - 
		AAA
			 Section - 	CCC

 Chapter - 
		BBB
			 Section - 	JJJ
			 Section - 	KKK
				 SubSection - 	LLL
				 SubSection - 	MMM
				 SubSection - 	NNN

 enter your choice
 1.insert book
 2.insert chapter
 3.insert section
 4.insert subsection
 5.display book
 6.display book BFS
 7.exit

 enter your choice
 1.insert book
 2.insert chapter
 3.insert section
 4.insert subsection
 5.display book
 6.display book BFS
 7.exit3

 Enter the name of chapter on which  you want to enter the sectionBBB

 how many sections you want to enter2

 enter the nameJJJ KKK

******
 enter the name
#####

 enter your choice
 1.insert book
 2.insert chapter
 3.insert section
 4.insert subsection
 5.display book
 6.display book BFS
 7.exit4

 Enter the name of chapter on which  you want to enter the sectionBBB

 enter name of section in which you want to enter the sub sectionKKK

 how many subsections you want to enter3

 enter the nameLLL MMM NNN

******
 enter the name
#####
 enter the name
#####

 enter your choice
 1.insert book
 2.insert chapter
 3.insert section
 4.insert subsection
 5.display book
 6.display book BFS
 7.exit5


 Book - ADS

 Chapter - 
		AAA
			 Section - 	CCC

 Chapter - 
		BBB
			 Section - 	JJJ
			 Section - 	KKK
				 SubSection - 	LLL
				 SubSection - 	MMM
				 SubSection - 	NNN

 enter your choice
 1.insert book
 2.insert chapter
 3.insert section
 4.insert subsection
 5.display book
 6.display book BFS
 7.exit7
  1.insert book
 2.insert chapter
 3.insert section
 4.insert subsection
 5.display book
 6.exit5
AdS
        AA      aa
        BB      bb      CC      cc
        DD      dd      EE      ee      HH      FF      ff      GG




*/
