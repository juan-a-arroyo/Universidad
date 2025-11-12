#include <iostream>
using namespace std;

class Person
{
    private:
        string LastName;
        string Name;
        int Age;
        string CURP;
        string NSS;
    public:
        Person();
        Person(string &, string &, int, string &, string &);
        string getLastName(){return LastName;}
        void setLastName(string lastname){LastName=lastname;}
        string getName(){return Name;}
        void setName(string name){Name=name;}
        int getAge(){return Age;}
        void setAge(int age){Age=age;}
        string getCURP(){return CURP;}
        void setCURP(string curp){CURP=curp;}
        string getNSS(){return NSS;}
        void setNSS(string nss){NSS=nss;}
};

Person::Person()
{
    LastName="";
    Name="";
    Age=0;
    CURP="";
    NSS=""; 
}
Person::Person(string &lastname, string &name, int age, string &curp, string &nss)
{
    LastName=lastname;
    Name=name;
    Age=age;
    CURP=curp;
    NSS=nss;    
}

class Teacher : public Person
{
    private:
        int Salary;
        string RFC;
    public:
        Teacher *next;
        Teacher();
        Teacher(string &, string &, int, string &, string &, int, string &);
        int getSalary(){return Salary;}
        void setSalary(int salary){Salary=salary;}
        string getRFC(){return RFC;}
        void setRFC(string rfc){RFC=rfc;}
};

Teacher::Teacher()
{
    Salary=0;
    RFC="";
}
Teacher::Teacher(string &lastname, string &name, int age, string &curp, string &nss, int salary, string &rfc):Person(lastname, name, age, curp, nss)
{
    Salary=salary;
    RFC=rfc;
    next=NULL;
}

class TeacherList : public Teacher
{
    private:
        Teacher *head, *tail;
    public:
        TeacherList(){head=tail=NULL;}
        void newTeacher(string &, string &, int, string &, string &, int, string &);
        void deleteTeacher(int i);
        void sortTeacher(TeacherList &);
        friend ostream& operator<<(ostream &out, const TeacherList &TList)
        {
            if(TList.head==NULL)
            {
                out<<"[Lista vacia]";
            }
            Teacher *temp;
            temp=TList.head;
            int x=1;
            while(temp!=NULL)
            {
                out<<x<<". "<<temp->getLastName()<<" "<<temp->getName()<<" / "<<"Edad: "<<temp->getAge()<<
                " / "<<"CURP: "<<temp->getCURP()<<" / "<<"NSS: "<<temp->getNSS()<<
                " / "<<"Sueldo Mensual: "<<temp->getSalary()<<" / "<<"RFC: "<<temp->getRFC()<<endl;
                temp=temp->next;
                x++;
            }
            out<<endl;
            return out;
        }
};

class Student : public Person
{
    private:
        int Grade;
        string Enrollment;
    public:
        Student *next;
        Student();
        Student(string &, string &, int, string &, string &, int, string &);
        int getGrade(){return Grade;}
        void setGrade(int grade){Grade=grade;}
        string getEnrollment(){return Enrollment;}
        void setEnrollment(string enrollment){Enrollment=enrollment;}
};

Student::Student()
{
    this->Grade=0;
    this->Enrollment="";
}
Student::Student(string &lastname, string &name, int age, string &curp, string &nss, int grade, string &enrollment):Person(lastname, name, age, curp, nss)
{
    Grade=grade;
    Enrollment=enrollment;
    next=NULL;
}

class StudentList : public Student
{
    private:
        Student *head, *tail;
    public:
        StudentList(){head=tail=NULL;}
        void newStudent(string &, string &, int, string &, string &, int, string &);
        void deleteStudent(int i);
        void sortStudent(StudentList &);
        friend ostream& operator<<(ostream &out, const StudentList &SList)
        {
            if(SList.head==NULL)
            {
                out<<"[Lista vacia]";
            }
            Student *temp;
            temp=SList.head;
            int x=1;
            while(temp!=NULL)
            {
                out<<x<<". "<<temp->getLastName()<<" "<<temp->getName()<<" / "<<"Edad: "<<temp->getAge()<<
                " / "<<"CURP: "<<temp->getCURP()<<" / "<<"NSS: "<<temp->getNSS()<<
                " / "<<"Promedio: "<<temp->getGrade()<<" / "<<"Matricula: "<<temp->getEnrollment()<<endl;
                temp=temp->next;
                x++;
            }
            out<<endl;
            return out;
        }
};

int main(void)
{
    StudentList SList;
    TeacherList TList;
    string lastname, name, curp, rfc_enrollment, nss;
    int opc, age, salary_grade, i, supr;
    bool del;
    do{
        system("CLS");
        cout<<"LISTA ESCOLAR"<<endl<<endl;
        cout<<"1. Mostrar lista de Alumnos"<<endl<<
        "2. Agregar Alumno"<<endl<<
        "3. Eliminar Alumno"<<endl<<
        "4. Mostrar lista de Profesores"<<endl<<
        "5. Agregar Profesor"<<endl<<
        "6. Eliminar Profesor"<<endl<<
        "7. Salir"<<endl<<endl<<
        "Seleccion: ";
        cin>>opc;
        del=false;
        if(opc==3)
        {
            opc=1;
            del=true;
        }
        if(opc==6)
        {
            opc=4;
            del=true;
        }
        switch(opc)
        {
        case 1:
            system("CLS");
            cout<<"LISTA DE ALUMNOS"<<endl<<endl;
            cout<<SList;
            if(del==true)
            {
                cout<<endl<<"Ingrese el numero de alumno a Eliminar: ";
                cin>>supr;
                supr-=1;
                SList.deleteStudent(supr);
            }
            system("PAUSE");
        break;

        case 2:
            system("CLS");
            cout<<"Apellidos: ";
            fflush(stdin);
            getline(cin, lastname);
            cout<<"Nombre(s): ";
            fflush(stdin);
            getline(cin, name);
            cout<<"Edad: ";
            cin>>age;
            cout<<"CURP: ";
            cin>>curp;
            cout<<"NSS: ";
            cin>>nss;
            cout<<"Calificacion: ";
            cin>>salary_grade;
            cout<<"Matricula: ";
            cin>>rfc_enrollment;
            SList.newStudent(lastname, name, age, curp, nss, salary_grade, rfc_enrollment);
            SList.sortStudent(SList);
        break;

        case 4:
            system("CLS");
            cout<<"LISTA DE PROFESORES"<<endl<<endl;
            cout<<TList;
            if(del==true)
            {
                cout<<endl<<"Ingrese el numero de alumno a Eliminar: ";
                cin>>supr;
                supr-=1;
                TList.deleteTeacher(supr);
            }
            system("PAUSE");
        break;

        case 5:
            system("CLS");
            cout<<"Apellidos: ";
            fflush(stdin);
            getline(cin, lastname);
            cout<<"Nombre(s): ";
            fflush(stdin);
            getline(cin, name);
            cout<<"Edad: ";
            cin>>age;
            cout<<"CURP: ";
            cin>>curp;
            cout<<"NSS: ";
            cin>>nss;
            cout<<"Sueldo Mensual: ";
            cin>>salary_grade;
            cout<<"RFC: ";
            cin>>rfc_enrollment;
            TList.newTeacher(lastname, name, age, curp, nss, salary_grade, rfc_enrollment);
            TList.sortTeacher(TList);
        break;

        case 7:
        system("CLS");
        cout<<"Gracias por usar el programa"<<endl<<endl;
        break;
        }
    }while(opc!=7);
    system("PAUSE");
}

void StudentList::newStudent(string &lastname, string &name, int age, string &curp, string &nss, int grade, string &enrollment)
{
    Student *vtx = new Student(lastname, name, age, curp, nss, grade, enrollment);
    vtx->next=head;
    head=vtx; 
    if(tail==NULL)
    {
        tail=head;
    }
}

void StudentList::deleteStudent(int i)
{
    int k;
    if(head==NULL)
    {
        cout<<"Nada que borrar"<<endl;
        return;
    }
    if(i==0)
    {
        Student *temp=head;
        head = head->next;
        delete temp;
        return;
    }
    Student *pre = head;
    for(k=0;k<i-1;k++)
        if(pre!=NULL)
            pre=pre->next;
    if(pre!=NULL)
    {
        Student *del = pre->next, *aft = del->next;
        pre->next = aft;
        delete del;
    }
    else
        cout<<"No existe valor en ese espacio"<<endl;
}

void StudentList::sortStudent(StudentList &SList)
{

    if(head!=NULL)
    {
        string lastname, name, curp, enrollment, nss;
        Student *val1, *val2;
        int i, j, v=1, age, grade, ctd=0;
        val1=SList.head;
        while(val1!=NULL)
        {
            ctd++;
            val1=val1->next;
        }
        val1=SList.head;
        val2=val1->next;
        for(i=0;i<ctd;i++)
            if(val2!=NULL)
            {
                if(val1->getLastName()[0]>val2->getLastName()[0]) //0 y 1
                    {
                        lastname=val1->getLastName(); //guardas elementos de 0
                        name=val1->getName();
                        age=val1->getAge();
                        curp=val1->getCURP();
                        nss=val1->getNSS();
                        grade=val1->getGrade();
                        enrollment=val1->getEnrollment();
                        val1->setLastName(val2->getLastName());
                        val1->setName(val2->getName());
                        val1->setAge(val2->getAge());
                        val1->setCURP(val2->getCURP());
                        val1->setNSS(val2->getNSS());
                        val1->setGrade(val2->getGrade());
                        val1->setEnrollment(val2->getEnrollment());
                        val2->setLastName(lastname);
                        val2->setName(name);
                        val2->setAge(age);
                        val2->setCURP(curp);
                        val2->setNSS(nss);
                        val2->setGrade(grade);
                        val2->setEnrollment(enrollment);
                    }
                val1=val1->next;
                val2=val2->next;
            }
    }
}

void TeacherList::newTeacher(string &lastname, string &name, int age, string &curp, string &nss, int salary, string &rfc)
{
    Teacher *vtx = new Teacher(lastname, name, age, curp, nss, salary, rfc);
    vtx->next=head;
    head=vtx; 
    if(tail==NULL)
    {
        tail=head;
    }
}

void TeacherList::deleteTeacher(int i)
{
    int k;
    if(head==NULL)
    {
        cout<<"Nada que borrar"<<endl;
        return;
    }
    if(i==0)
    {
        Teacher *temp=head;
        head = head->next;
        delete temp;
        return;
    }
    Teacher *pre = head;
    for(k=0;k<i-1;k++)
        if(pre!=NULL)
            pre=pre->next;
    if(pre!=NULL)
    {
        Teacher *del = pre->next, *aft = del->next;
        pre->next = aft;
        delete del;
    }
    else
        cout<<"No existe valor en ese espacio"<<endl;
}

void TeacherList::sortTeacher(TeacherList &TList)
{

    if(head!=NULL)
    {
        string lastname, name, curp, rfc, nss;
        Teacher *val1, *val2;
        int i, j, v=1, age, salary, ctd=0;
        val1=TList.head;
        while(val1!=NULL)
        {
            ctd++;
            val1=val1->next;
        }
        val1=TList.head;
        val2=val1->next;
        for(i=0;i<ctd;i++)
            if(val2!=NULL)
            {
                if(val1->getLastName()[0]>val2->getLastName()[0]) //0 y 1
                    {
                        lastname=val1->getLastName(); //guardas elementos de 0
                        name=val1->getName();
                        age=val1->getAge();
                        curp=val1->getCURP();
                        nss=val1->getNSS();
                        salary=val1->getSalary();
                        rfc=val1->getRFC();
                        val1->setLastName(val2->getLastName());
                        val1->setName(val2->getName());
                        val1->setAge(val2->getAge());
                        val1->setCURP(val2->getCURP());
                        val1->setNSS(val2->getNSS());
                        val1->setSalary(val2->getSalary());
                        val1->setRFC(val2->getRFC());
                        val2->setLastName(lastname);
                        val2->setName(name);
                        val2->setAge(age);
                        val2->setCURP(curp);
                        val2->setNSS(nss);
                        val2->setSalary(salary);
                        val2->setRFC(rfc);
                    }
                val1=val1->next;
                val2=val2->next;
            }
    }
}