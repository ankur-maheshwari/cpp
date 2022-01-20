class Student {
    public :                          // output = compilation error

    const int rollNumber;
    int age;

};


int main() {
    Student s1;
    s1.rollNumber = 101;
    s1.age = 20;

    cout << s1.rollNumber << " " << s1.age;

}
