#include <iostream>

struct student
{
    char name[12];
    unsigned int age;
};
int strcpy_with_overflow(void)
{
    struct student a_student = {"01234567890",10};
    printf("studnet name is \"%s\", age is %d\n",
           a_student.name,a_student.age);
    strcpy(a_student.name,"012345678901");
    printf("studnet name is \"%s\", age is %d\n",
           a_student.name,a_student.age);
    return 0;
}
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

