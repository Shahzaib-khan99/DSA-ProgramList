/* C++ Basic Operations on Binary Files
 * This program demonstrates the searching
 * operation in a C++ program. Here the
 * searching operations performed, on
 * the records implemented through classes
 */


#include <iostream>
#include <conio.h>
#include<fstream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

 
struct student
{
   int rollno;
   char name[20];
   char branch[3];
   float marks;
   char grade;
};

 void getdata(student );
 void putdata(student );
 int main()
{
   system("cls");
   student stud;
   ofstream fout("d:\\marks.dat", ios::app);
   char ans='y';
   while(ans=='y' || ans=='Y')
   {
      getdata(stud);
      fout.write((char *)&stud, sizeof(stud));
      cout<<"Record added to the file\n";
      cout<<"\nWant to enter more ? (y/n)..";
      cin>>ans;
   }
   fout.close();

   system("cls");
   int rno;
   char found;
   ifstream fin("d:\\marks.dat", ios::in);

   found = 'f';
   cout<<"Enter rollno you want to search for: ";
   cin>>rno;

   while(!fin.eof())       // end-of-file used here
   {
      fin.read((char *)&stud, sizeof(stud));
      if(stud.rollno == rno)
      {
         cout<<"Record found at roll number "<<rno<<". Here is the record\n";

         putdata(stud);
         found = 't';
        break;
      }
    }
  if(found=='f')
   {
      cout<<"\nRecord not found at this roll number..!!\n";
      cout<<"Press any key to exit...\n";
      getch();
      exit(2);
  }
   
   
   fin.close();
   cout<<"\nPress any key to exit...\n";
   getch();
}
      
	  
	  void getdata(student st)
      {
         cout<<"Enter Rollno: ";
         cin>>st.rollno;
         cout<<"Enter Name: ";
         cin>>st.name;
         cout<<"Enter Branch: ";
         cin>>st.branch;
         cout<<"Enter Marks: ";
         cin>>st.marks;

         if(st.marks>=75)
         {
            st.grade = 'A';
         }
         else if(st.marks>=60)
         {
            st.grade = 'B';
         }
         else if(st.marks>=50)
         {
            st.grade = 'C';
         }
         else if(st.marks>=40)
         {
            st.grade = 'D';
         }
         else
         {
            st.grade = 'F';
         }
      }

      void putdata(student st)
      {
         cout<<"Name \t\t RollNo \t Marks \t\t Grade\n";
		 cout<<st.name<<"\t\t "<<st.rollno<<" \t\t ";
         cout<<st.marks<<"\t\t "<<st.grade<<" "<<"\n";
      }

      



