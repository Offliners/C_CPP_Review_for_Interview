# Chatper 6 - 指標與結構
### 結構簡介
C語言的結構有幾種不同的宣告方式，在以下的宣告中，結構的名稱之前加上了底線以供識別，雖然不一定要如此，但這是常見的命名慣例:
```c
struct _person {
    char* firstName;
    char* lastName;
    char* title;
    unsigned int age;
};
```

結構宣告時通常會使用typedef關鍵字以簡化後續程式的使用，以下是同樣_person結構的例子:
```c
typedef struct _person {
    char* firstName;
    char* lastName;
    char* title;
    unsigned int age;
} Person;
```

人員 (person)的實體可宣告如下:
```c
Person person;
```

或是也可以宣告指向Person的指標，並配置所需的記憶體，如下:
```c
Person *ptrPerson;
ptrPerson = (Person*) malloc(sizeof(Person));
```

如果使用person這樣直接指派的宣告方式，可以使用點符號 (dot notation)存取結構中的欄位。以下程式中，指派了firstName與age欄位:
```c
Person person;
person.firstName = (char*)malloc(strlen("Emily")+1);
strcpy(person.firstName, "Emily");
person.age = 23;
```

然而，使用結構指標，就需要使用指向運算子 (point-to operator)，如以下程式:
```c
Person *ptrPerson;
ptrPerson = (Person*)malloc(sizeof(Person));
ptrPerson->firstName = (char*)malloc(strlen("Emily")+1);
strcpy(ptrPerson->firstName, "Emily");
ptrPerson->age = 23;
```

並不一定非得使用指向運算子不可，也可以解參考指標，再使用點符號，以下程式與上述程式執行了相同的指派操作:
```c
Person *ptrPerson;
ptrPerson = (Person*)malloc(sizeof(Person));
(*ptrPerson).firstName = (char*)malloc(strlen("Emily")+1);
strcpy((*ptrPerson).firstName, "Emily");
(*ptrPerson).age = 23;
```