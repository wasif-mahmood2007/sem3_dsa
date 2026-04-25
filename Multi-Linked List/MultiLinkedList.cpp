#include <iostream>
using namespace std;

struct Student;

struct Course
{
    int CNo;
    Course* next;
    Student* studentList;
};

struct Student
{
    int SNo;
    Student* next;
};

Course* courseList = NULL;

void insertCourse(int CNo)
{
    Course* tmp = new Course;
    tmp->CNo = CNo;
    tmp->next = NULL;
    tmp->studentList = NULL;

    if(courseList == NULL)
    {
        courseList = tmp;
        cout << "The course " << CNo << " have been added to the Course List." << endl;
        return;
    }
    else
    {
        Course* cur = courseList;
        while(cur->next != NULL)
        {
            cur = cur->next;
        }
        cur->next = tmp;
        cout << "The course " << CNo << " have been added to the Course List." << endl;
        return;
    }
}

void insertStudent(int CNo, int SNo)
{
    Course* reqCourse = courseList;
    while(reqCourse != NULL && reqCourse->CNo != CNo)
    {
        reqCourse = reqCourse->next;
    }
    if(reqCourse == NULL)
    {
        cout << "Entered course " << CNo << " does not exist." << endl;
        return;
    }

    Student* tmp = new Student;
    tmp->SNo = SNo;
    tmp->next = NULL;

    if(reqCourse->studentList == NULL)
    {
        reqCourse->studentList = tmp;
        cout << "Student " << SNo << " have been added to the Course " << CNo << "." << endl;
        return;
    }
    else
    {
        Student* cur = reqCourse->studentList;
        while(cur->next != NULL)
        {
            cur = cur->next;
        }
        cur->next = tmp;
        cout << "Student " << SNo << " have been added to the Course " << CNo << "." << endl;
        return;
    }
}

void deleteCourse(int CNo)
{
    if(courseList == NULL)
    {
        cout << "Course List is empty." << endl;
        return;
    }
    else if(courseList->CNo == CNo)
    {
        Student* curS = courseList->studentList;
        while(curS != NULL)
        {
            Student* tmpS = curS;
            curS = curS->next;
            delete tmpS;
        }

        Course* tmpC = courseList;
        courseList = courseList->next;
        delete tmpC;
        cout << "Course " << CNo << " deleted successfully." << endl;
        return;
    }
    else
    {
        Course* curC = courseList;
        Course* nextC = courseList->next;
        while(nextC != NULL)
        {
            if(nextC->CNo == CNo)
            {
                Student* curS = nextC->studentList;
                while(curS != NULL)
                {
                    Student* tmpS = curS;
                    curS = curS->next;
                    delete tmpS;
                }

                curC->next = nextC->next;
                delete nextC;
                cout << "Course " << CNo << " deleted successfully." << endl;
                return;
            }
            curC = curC->next;
            nextC = nextC->next;
        }
    }
    cout << "Course " << CNo << " does not exist." << endl;
    return;
}

void deleteStudent(int SNo)
{
    if(courseList == NULL)
    {
        cout << "Course List is empty." << endl;
        return;
    }

    for(Course* curC = courseList; curC != NULL; curC = curC->next)
    {
        if(curC->studentList == NULL)
        {
            continue;
        }
        else if(curC->studentList->SNo == SNo)
        {
            Student* tmp = curC->studentList;
            curC->studentList = curC->studentList->next;
            delete tmp;
            cout << SNo << " deleted successfully from course " << curC->CNo << "." << endl;
            return;
        }
        else
        {
            Student* curS = curC->studentList;
            Student* nextS = curC->studentList->next;
            while(nextS != NULL)
            {
                if(nextS->SNo == SNo)
                {
                    curS->next = nextS->next;
                    delete nextS;
                    cout << SNo << " deleted successfully from course " << curC->CNo << "." << endl;
                    return;
                }
                curS = curS->next;
                nextS = nextS->next;
            }
        }
    }
    cout << SNo << " not found, thus can't be deleted." << endl;
    return;
}

void deleteStudentFromGivenCourse(int CNo, int SNo)
{
    Course* reqCourse = courseList;
    while(reqCourse != NULL && reqCourse->CNo != CNo)
    {
        reqCourse = reqCourse->next;
    }
    if(reqCourse == NULL)
    {
        cout << "Entered course " << CNo << " does not exist." << endl;
        return;
    }

    if(reqCourse->studentList == NULL)
    {
        cout << "No students exists inside the course " << CNo << "." << endl;
        return;
    }
    else if(reqCourse->studentList->SNo == SNo)
    {
        Student* tmp = reqCourse->studentList;
        reqCourse->studentList = reqCourse->studentList->next;
        delete tmp;
        cout << SNo << " deleted successfully from course " << CNo << "." << endl;
        return;
    }
    else
    {
        Student* curS = reqCourse->studentList;
        Student* nextS = reqCourse->studentList->next;
        while(nextS != NULL)
        {
            if(nextS->SNo == SNo)
            {
                curS->next = nextS->next;
                delete nextS;
                cout << SNo << " deleted successfully from course " << CNo << "." << endl;
                return;
            }
            curS = curS->next;
            nextS = nextS->next;
        }
    }
    cout << SNo << " not found, thus can't be deleted." << endl;
    return;
}

void searchCourse(int CNo)
{
    for(Course* cur = courseList; cur != NULL; cur = cur->next)
    {
        if(cur->CNo == CNo)
        {
            cout << "Course " << CNo << " found." << endl;
            return;
        }
    }
    cout << "Course " << CNo << " not found." << endl;
    return;
}

void searchStudent(int SNo)
{
    if(courseList == NULL)
    {
        cout << "Course List is empty." << endl;
        return;
    }

    for(Course* curC = courseList; curC != NULL; curC = curC->next)
    {
        Student* curS = curC->studentList;
        while(curS != NULL)
        {
            if(curS->SNo == SNo)
            {
                cout << "Student " << SNo << " found in course " << curC->CNo << "." << endl;
                return;
            }
            curS = curS->next;
        }
    }
    cout << "Student " << SNo << " not found." << endl;
    return;
}

void searchStudentFromGivenCourse(int CNo, int SNo)
{
    Course* reqCourse = courseList;
    while(reqCourse != NULL && reqCourse->CNo != CNo)
    {
        reqCourse = reqCourse->next;
    }
    if(reqCourse == NULL)
    {
        cout << "Entered course " << CNo << " does not exist." << endl;
        return;
    }

    for(Student* reqStudent = reqCourse->studentList; reqStudent != NULL; reqStudent = reqStudent->next)
    {
        if(reqStudent->SNo == SNo)
        {
            cout << "Student " << SNo << " found in course " << CNo << "." << endl;
            return;
        }
    }
    cout << "Student " << SNo << " not found." << endl;
    return;
}

void displayCourseList()
{
    if(courseList == NULL)
    {
        cout << "Course List is empty." << endl;
        return;
    }

    cout << "Course List:";
    for(Course* print = courseList; print != NULL; print = print->next)
    {
        cout << " " << print->CNo;
    }
    cout << endl;
}

void displayStudentListInGivenCourse(int CNo)
{
    Course* reqCourse = courseList;
    while(reqCourse != NULL && reqCourse->CNo != CNo)
    {
        reqCourse = reqCourse->next;
    }
    if(reqCourse == NULL)
    {
        cout << "Entered course " << CNo << " does not exist." << endl;
        return;
    }

    cout << CNo << ":";
    for(Student* print = reqCourse->studentList; print != NULL; print = print->next)
    {
        cout << " " << print->SNo;
    }
    cout << endl;
}

void display()
{
    if(courseList == NULL)
    {
        cout << "Course List is empty." << endl;
        return;
    }

    for(Course* printCourse = courseList; printCourse != NULL; printCourse = printCourse->next)
    {
        cout << printCourse->CNo << ":";
        Student* printStudent = printCourse->studentList;
        while(printStudent != NULL)
        {
            cout << " " << printStudent->SNo;
            printStudent = printStudent->next;
        }
        cout<< endl;
    }
}

int main()
{
    //Course insertion
    insertCourse(150);
    insertCourse(152);
    insertCourse(154);
    insertCourse(156);
    insertCourse(158);
    insertCourse(160);

    //Display Course List
    displayCourseList();

    //Inserting Students into the Courses
    insertStudent(150, 1);
    insertStudent(150, 2);
    insertStudent(150, 3);
    insertStudent(150, 4);
    insertStudent(152, 6);
    insertStudent(152, 7);
    insertStudent(152, 8);
    insertStudent(152, 9);
    insertStudent(154, 22);
    insertStudent(154, 23);
    insertStudent(154, 24);
    insertStudent(154, 25);
    insertStudent(156, 45);
    insertStudent(156, 46);
    insertStudent(156, 48);
    insertStudent(156, 49);
    insertStudent(158, 32);
    insertStudent(158, 33);
    insertStudent(158, 34);
    insertStudent(158, 35);
    insertStudent(160, 64);
    insertStudent(160, 65);
    insertStudent(160, 66);
    insertStudent(160, 67);
    insertStudent(250, 99); //Inserting a student into the Non-existing Course

    //Display all the students in a course
    displayStudentListInGivenCourse(152);
    displayStudentListInGivenCourse(153); //Display all the students in a course that does not exists.

    //Removing students
    deleteStudent(45); //Remove first student of the course
    deleteStudent(5); //Remove non-existant student
    deleteStudent(48); //Remove student from middle of the course
    deleteStudent(49); //Remove last student of the course
    displayStudentListInGivenCourse(156);

    //Removing student from given course
    deleteStudentFromGivenCourse(150, 1); //Remove first student of the course
    deleteStudentFromGivenCourse(150, 7); //Remove non-existant student
    deleteStudentFromGivenCourse(150, 3); //Remove student from middle of the course
    deleteStudentFromGivenCourse(150, 4); //Remove last student of the course
    displayStudentListInGivenCourse(150);
    deleteStudentFromGivenCourse(150, 2);
    deleteStudentFromGivenCourse(150, 1); //Remove from an empty course

    //Remove course from the course list
    deleteStudent(156);
    deleteStudent(156); //Remove non-existant course

    //Search course
    searchCourse(150);
    searchCourse(350); //When course does not exists

    //Search student
    searchStudent(64);
    searchStudent(82); //When student does not exists

    //Search student from given course
    searchStudentFromGivenCourse(154, 25);
    searchStudentFromGivenCourse(155, 25); //When course does not exists
    searchStudentFromGivenCourse(154, 5); //When student does not exists in the given course

    //Display All
    display();
}