#include<iostream>
using namespace std;
typedef struct node
{
int rollno;
string name;
int History=0;
int Marathi=0;
int English=0;
int Science=0;
int Total=0;
struct node *next;
}NODE,*PNODE;
class student
{
private:
PNODE head;
PNODE tail;
int isize;
public:
student()
{
head=NULL;
isize=0;
tail=NULL;
}
~student()
{
}
void addstudent(char name[])
{
cout<<"\n";
PNODE newn=NULL;
newn=new NODE;
static int irollno=1;
newn->rollno=irollno;
newn->name=name;
newn->next=NULL;
if(head==NULL)
{
head=newn;
tail=newn;
}
else
{
tail->next=newn;
tail=tail->next;
}
cout<<"ROLL NUMBER OF THIS STUDENT IS\n";
cout<<irollno;
irollno++;
isize++;
cout<<"\n\n";
} 
void display()
{
PNODE temp=head;
int i=0,final=0;
for(i=1;i<=isize;i++)
{

cout<<"****************************************\n";
cout<<"ROLL NO OF STUDENT IS:";
cout<<temp->rollno;
cout<<"\n";
cout<<"NAME OF STUDENT IS:";
cout<<temp->name;
cout<<"\n";
cout<<"MARKS IN HISTORY:";
cout<<temp->History;
cout<<"\n";
cout<<"\n";
cout<<"MARKS IN MARATHI:";
cout<<temp->Marathi;
cout<<"\n";
cout<<"\n";
cout<<"MARKS IN ENGLISH:";
cout<<temp->English;
cout<<"\n";
cout<<"\n";
cout<<"MARKS IN SCIENCE:";
cout<<temp->Science;
cout<<"\n";
cout<<"\n";
cout<<"STUDENT GOT TOTAL MARKS IS:";
final=temp->Science+temp->History+temp->English+temp->Marathi;
cout<<final;
cout<<"\n";
cout<<"***************************************\n\n";
temp=temp->next;
}
cout<<"\n\n";
}
void remove(int ino)
{
PNODE temp=head;
PNODE semp=head;
if(ino>isize)
{
cout<<"YOU HAVE ENTERED WRONG ROLLNO\n";
}
if(head->next==NULL)
{
head=NULL;
delete semp;
}
else if(head->rollno==ino)
{
head=temp->next;
delete semp;
}
else
{
while(temp->next->rollno!=ino)
{
temp=temp->next;
semp=semp->next;
}
if(temp->next==NULL)
{
delete semp->next;
temp->next=NULL;
}
else
{
semp=semp->next;
temp->next=semp->next;
delete semp;
}

}
isize--;
}
void studentmarks(int history,int marathi,int english,int science,int ino)
{
PNODE temp=head;
int itotal=0;
if(ino>isize)
{
return;
}


{
while(temp->rollno!=ino)
{
temp=temp->next;
}
temp->History=history;
temp->Science=science;
temp->English=english;
temp->Marathi=marathi;
itotal=history+marathi+science+english;
temp->Total=itotal;
}
}
updatehistory(int ino,int imarks)
{
if(ino>isize)
{
return -1;
}
PNODE temp=head;
while(temp->rollno!=ino)
{
temp=temp->next;
}
temp->History=imarks;
}

updatemarathi(int ino,int imarks)
{
PNODE temp=head;
if(ino>isize)
{
return -1;
}
while(temp->rollno!=ino)
{
temp=temp->next;
}
temp->Marathi=imarks;
}

updateenglish(int ino,int imarks)
{
PNODE temp=head;
if(ino>isize)
{
return -1;
}
while(temp->rollno!=ino)
{
temp=temp->next;
}
temp->English=imarks;
}

updatescience(int ino,int imarks)
{
PNODE temp=head;
if(ino>isize)
{
return -1;
}
while(temp->rollno!=ino)
{
temp=temp->next;
}
temp->Science=imarks;
}

void showresult(int ino)
{
if(ino>isize)
{
return;
}
PNODE temp=head;
while(temp->rollno!=ino)
{
temp=temp->next;
}
cout<<"RESULT OF STUDENT\n";
cout<<"ROLLNO:";
cout<<temp->rollno;
cout<<"\n\n";
if(temp->History>=35)
{
cout<<"History : PASS";
cout<<"\n\n";
}
else
{
cout<<"History : FAIL";
cout<<"\n\n";
}

if(temp->Marathi>=35)
{
cout<<"Marathi : PASS";
cout<<"\n\n";
}
else
{
cout<<"Marathi : FAIL";
cout<<"\n\n";
}

if(temp->English>=35)
{
cout<<"English : PASS";
cout<<"\n\n";
}
else
{
cout<<"English : FAIL";
cout<<"\n\n";
}

if(temp->Science>=35)
{
cout<<"Science : PASS";
cout<<"\n\n";
}
else
{
cout<<"Science : FAIL";
cout<<"\n\n";
}

}


};
int main()
{
int ichoice=1,rollno=0,ino=0,history=0,marathi=0,science=0,english=0,imarks=0;
char name[100]={'\0'};
student *obj=new student;
while(ichoice!=0)
{

cout<<"ENTER CHOICE\n";
cout<<"0:EXIT\n";
cout<<"1:ADD STUDENT\n";
cout<<"2:DISPLAY INFORMATION OF ALL STUDENTS\n";
cout<<"3:REMOVE  STUDENT"<<"\n";
cout<<"4:ADD STUDENTS MARKS OF ALL SUBJECTS\n";
cout<<"5:ADD OR UPDATE MARKS OF HISTORY SUBJECT\n";
cout<<"6:ADD OR UPDATE MARKS OF MARATHI SUBJECT\n";
cout<<"7:ADD OR UPDATE MARKS OF ENGLISH SUBJECT\n";
cout<<"8:ADD OR UPDATE MARKS  SCIENCE SUBJECT\n";
cout<<"9:SHOW STUDENT RESULT\n";
cin>>ichoice;

switch(ichoice)
{
case 0:
cout<<"THANK YOU FOR USING THIS APPLICATION\n";
delete obj;
break;

case 1:
cout<<"ENTER NAME OF STUDENT\n";
scanf(" %[^'\n']s",name);
obj->addstudent(name);
break;

case 2:
obj->display();
break;

case 3:
cout<<"ENTER ROLL NUMBER OF STUDENT";
cin>>ino;
obj->remove(ino);
break;

case 4:
cout<<"ENTER ROLL NUMBER TO ADD MARKS OF ALL SUBJECTS\n";
cin>>ino;
cout<<"ENTER MARKS OF HISTORY\n";
cin>>history;
cout<<"ENTER MARKS OF MARATHI\n";
cin>>marathi;
cout<<"ENTER MARKS OF ENGLISH\n";
cin>>english;
cout<<"enter marks of SCIENCE subject\n";
cin>>science;
obj->studentmarks(history,marathi,english,science,ino);
break;

case 5:
cout<<"ENTER ROLL NUMBER";
cin>>ino;
cout<<"ENTER MARKS FOR UPDATE";
cin>>imarks;
obj->updatehistory(ino,imarks);
break;

case 6:
cout<<"ENTER ROLL NUMBER";
cin>>ino;
cout<<"ENTER MARKS FOR UPDATE";
cin>>imarks;
obj->updatemarathi(ino,imarks);
break;

case 7:
cout<<"ENTER ROLL NUMBER";
cin>>ino;
cout<<"ENTER MARKS FOR UPDATE";
cin>>imarks;
obj->updateenglish(ino,imarks);
break;

case 8:
cout<<"ENTER ROLL NUMBER\n";
cin>>ino;
cout<<"ENTER MARKS FOR UPDATE\n";
cin>>imarks;
obj->updatescience(ino,imarks);
break;

case 9:
cout<<"ENTER ROLL NUMBER";
cin>>ino;
obj->showresult(ino);
break;


default:
cout<<"YOU HAVE ENTERED WRONG INPUT\n";
break;
}
}
return 0;
}