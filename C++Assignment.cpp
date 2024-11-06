#include <iostream>
using namespace std;

class Student 
{
    public:
        int reg_no;
        string name;
        string parent_name;
        int semester;
        int roll_no;
        int attendance; 
        int marks[5];
        float percentage;

    public:
    void getDetails() 
    {
        cout<<"Enter Registration Number: "<<endl;
        cin >> reg_no;
        cout<<"Enter Name: "<<endl;
        cin>>name;
        cout<<"Enter Parent's Name: "<<endl;
        cin>>parent_name;
        cout<<"Enter Semester: "<<endl;
        cin>>semester;
        cout<<"Enter Roll Number: "<<endl;
        cin>>roll_no;
        cout<<"Enter Attendance (Classes attended): "<<endl;
        cin>>attendance;
        for(int i = 0; i < 5; i++) 
        {
            cout << "Marks of " << (i + 1) << " subject: "<<endl;
            cin >> marks[i];
        }
    }
    void showDetails() 
    {
        cout<<"Registration Number: "<<reg_no<<endl
            <<"Name: "<<name<<endl
            <<"Parent's Name: "<<parent_name<<endl
            <<"Semester: "<<semester<<endl
            <<"Roll Number: "<<roll_no<<endl
            <<"Attendance: "<<attendance<<endl
            <<"Marks: "<<endl;
        for (int i = 0; i < 5; i++) 
        {
            cout<<marks[i]<<" "<<endl;
        }
    }
    void print_Attendance() 
    {
        cout<<"Roll Number: "<<roll_no<<", Name: "<<name<<", Attendance: "<<attendance<<endl;
    }
    void show_shortage() 
    {
        if (attendance < 75) 
        {
            cout<<"Roll Number: "<<roll_no<<", Name: "<<name<<", Attendance: " <<attendance<<"% (Below minimum)"<<endl;
        }
    }
    void show_percentage() 
    {
        int total = 0;
            for (int i = 0; i < 5; i++) 
            {
                total += marks[i];
            }
            percentage = (total/500.0) * 100.0;
            cout<<"Percentage for "<<name<<": "<<percentage<<"%"<<endl;
    }
   void show_90_percentage() 
    {
        if (percentage > 90 && attendance > 90) 
        {
            cout<<"Roll Number: "<<roll_no<<", Name: "<<name<<" has percentage and attendance above 90%"<<endl;
        }
    }
    void show_top5(Student students[], int n) 
    {
        for(int i = 0; i < n - 1; i++) 
        {
            for(int j = i + 1; j < n; j++) 
            {
                if (students[j].percentage > students[i].percentage) 
                {
                    Student temp = students[i];
                    students[i] = students[j];
                    students[j] = temp;
                }
            }
        }
        cout<<"Top 5 Students of the class are:"<<endl;
        for (int i = 0; i < 5; i++) 
        {
            cout<<"Rank "<<(i + 1)<<" Name: "<<students[i].name<<": "<<students[i].percentage<<", Roll Number: "<<students[i].roll_no<<endl;
        }
    }
};
int main() 
{ 
    Student students[10];
    for (int i = 0; i < 10; i++) 
    {
        cout<<"Enter details for Student " << (i + 1)<<endl;
        students[i].getDetails();
        cout<<endl;
    }

    for (int i = 0; i < 10; i++) 
    {
        cout<<"Details of Student no. "<<(i + 1)<<endl;
        students[i].showDetails();
        cout<<endl;
    }

    cout<<"Attendance for each Student:"<<endl;
    for (int i = 0; i < 10; i++) 
    {
        students[i].print_Attendance();
        cout<<endl;
    }

    cout<<"Students with shortage: "<<endl;
    for (int i = 0; i < 10; i++) {
        students[i].show_shortage();
        cout<<endl;
    }
    
    cout<<"Percentage of Marks for each Student:"<<endl;
    for(int i = 0; i < 10; i++)
    {
        students[i].show_percentage();
        cout<<endl;
    }
    cout << "Students with attendance and percentage above 90% are:"<<endl;
    for (int i = 0; i < 10; i++) 
    {
        students[i].show_90_percentage();
        cout<<endl;
    }

    students[10].show_top5(students, 10);
return 0;
}
