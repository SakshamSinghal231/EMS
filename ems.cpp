#include<iostream>
#include<conio.h>
#include<string.h>

using namespace std;
string pass ="";

// Global declaration
int count = 0;
int q = 1;

// Structure declaration
struct node {
	struct node* prev;
	int empID;
	long long int phNo;
	float sal;
	char name[20], dept[10], desg[20], pass[10];
	struct node* next;
} *temp, *temp1, *temp2, *temp4, *temp5, *temp6;

struct node *head = NULL;

void sortList() {
    struct node *current = NULL, *index = NULL;
    int empID;
    long long int phNo;
    float sal;
    char name[20], dept[10], desg[20], pass[10];

    if(head == NULL) {
        return;
    }
    else {
        for(current = head; current->next != NULL; current = current->next) {
            for(index = current->next; index != NULL; index = index->next) {
                if(current->empID > index->empID) {
                    //Swapping empID
                    empID = current->empID;
                    current->empID = index->empID;
                    index->empID = empID;
                    //Swapping phNo
                    phNo = current->phNo;
                    current->phNo = index->phNo;
                    index->phNo = phNo;
                    //Swapping name
                    strcpy(name, current->name);
                    strcpy(current->name, index->name);
                    strcpy(index->name, name);
                    //Swapping dept
                    strcpy(dept, current->dept);
                    strcpy(current->dept, index->dept);
                    strcpy(index->dept, dept);
                    //Swapping desg
                    strcpy(desg, current->desg);
                    strcpy(current->desg, index->desg);
                    strcpy(index->desg, desg);
                    //Swapping pass
                    strcpy(pass, current->pass);
                    strcpy(current->pass, index->pass);
                    strcpy(index->pass, pass);
                }
            }
        }
    }
}

// Function to create node
void create()
{
	int empID;
	long int phNo;
	float sal;
	char name[20], dept[10], desg[20], pass[10];
	temp = new node;
	temp->prev = NULL;
	temp->next = NULL;

    for(int i=0; i<40; i++){cout<<"_";}

    int check=1;

    cout<<endl<<"\n Enter Employee ID [max 4 digits]: ";
    cin>>empID;

    if(head!=NULL){
        while(check){
            node *temp = head;
            while(temp!=NULL){
                if(empID==temp->empID){
                    cout<<"\nNot a Unique Employee ID\n";
                    cout<<endl<<"\n Enter Employee ID [max 4 digits]: ";
                    cin>>empID;
                    check=1;
                    break;
                }
                temp=temp->next;
            }
            if(temp==NULL){
                check*=0;
            }
        }
    }
    cout<<endl<<"----------------------------------------";
    cout<<endl<<" Enter First Name of Employee    : ";
    cin>>name;
    cout<<endl<<"----------------------------------------";
    cout<<endl<<" Enter Department                : ";
    cin>>dept;
    cout<<endl<<"----------------------------------------";
    cout<<endl<<" Enter Designation               : ";
    cin>>desg;
    cout<<endl<<"----------------------------------------";
    cout<<endl<<" Enter Employee Salary           : ";
    cin>>sal;
    cout<<endl<<"----------------------------------------";
    cout<<endl<<" Enter Employee Phone No         : ";
    cin>>phNo;
    cout<<endl<<"----------------------------------------";
    cout<<endl<<" Enter Employee Password         : ";
    cin>>pass;
    cout<<endl;
    for(int i=0; i<40; i++){cout<<"_";}
    temp->empID = empID;
    strcpy(temp->name, name);
    strcpy(temp->dept, dept);
    strcpy(temp->desg, desg);
    strcpy(temp->pass, pass);
    temp->sal = sal;
    temp->phNo = phNo;
	count++;
	system("cls");
}

void login();

//Function to Show Employee Data when Called by an Employer
void showdatabyempIDbyemployer()
{
    int empID, check=1;
    cout<<" Enter an Employee ID: ";
    cin>>empID;
    temp6 = head;
    while (temp6!=NULL){
        if(temp6->empID==empID){
            check*=0;
            break;
        }
        temp6=temp6->next;
    }

    char endFrontScreen[2];
    if(check){
        cout<<" No such data"<<endl<<" Press Enter to go to Main Menu"<<endl;
        fflush(stdin);
        gets(endFrontScreen);
        system("pause");
        system("cls");
        return;
    }

    cout<<"\n Name       : "<<temp6->name;
    cout<<"\n Department : "<<temp6->dept;
    cout<<"\n Designation: "<<temp6->desg;
    cout<<"\n Salary     : "<<temp6->sal;
    cout<<"\n Phone No.  : "<<temp6->phNo<<endl<<endl;
    system("pause");
    system("cls");

}

//Function to Show Employee Data when Called by an Employee
void showdatabyempIDbyemployee()
{
    int empID, check=1;
    cout<<" Enter an Employee ID: ";
    cin>>empID;
    temp6 = head;
    while (temp6!=NULL){
        if(temp6->empID==empID){
            check*=0;
            break;
        }
        temp6=temp6->next;
    }

    char endFrontScreen[2];
    if(check){
        cout<<" No such data"<<endl<<" Press Enter to go to Main Menu"<<endl;
        fflush(stdin);
        gets(endFrontScreen);
        system("pause");
        system("cls");
        return;
    }

    cout<<"\n Name       : "<<temp6->name;
    cout<<"\n Department : "<<temp6->dept;
    cout<<"\n Designation: "<<temp6->desg;
    cout<<"\n Phone No.  : "<<temp6->phNo<<endl<<endl;
    system("pause");
    system("cls");

}

//Function to Modify Employee Data when Called by an Employer
void modifydatabyemployer()
{
    int empID;
	long int phNo;
	float sal;
	char name[20], dept[10], desg[20];
    int check=1;
    cout<<" Enter an Employee ID: ";
    cin>>empID;
    node *temp5 = head;
    while (temp5!=NULL){
        if(temp5->empID==empID){
            check*=0;
            break;
        }
        temp5=temp5->next;
    }

    char endFrontScreen[2];
    if(check){
        cout<<"No such data"<<endl<<"Press Enter to go to Main Menu"<<endl;
        fflush(stdin);
        gets(endFrontScreen);
        return;
    }

    cout<<endl<<"----------------------------------------";
    cout<<endl<<" Enter First Name of Employee    : ";
    cin>>name;
    cout<<endl<<"----------------------------------------";
    cout<<endl<<" Enter Department                : ";
    cin>>dept;
    cout<<endl<<"----------------------------------------";
    cout<<endl<<" Enter Designation               : ";
    cin>>desg;
    cout<<endl<<"----------------------------------------";
    cout<<endl<<" Enter Employee Salary           : ";
    cin>>sal;
    cout<<endl<<"----------------------------------------";
    cout<<endl<<" Enter Employee Phone No         : ";
    cin>>phNo;
    cout<<endl;

 	strcpy(temp5->name, name);
	strcpy(temp5->dept, dept);
	strcpy(temp5->desg, desg);
	temp5->sal = sal;
	temp5->phNo = phNo;

	system("cls");
}

//Function to Modify Employee Data when Called by an Employee
void modifydatabyemployee()
{
    int empID;
	long int phNo;
	float sal;
	char name[20], dept[10], desg[20], pass[10];
    int check=1, checkPass=1;

    cout<<" Enter an Employee ID: ";
    cin>>empID;
    cout<<" Enter Password      : ";
    cin>>pass;

    node *temp5 = head;
    while (temp5!=NULL){
        if(temp5->empID==empID){
            check*=0;
            if(!strcmp(temp5->pass, pass)){
                checkPass*=0;
                break;
            }
            break;
        }
        temp5=temp5->next;
    }

    char endFrontScreen[2];
    if(check){
        cout<<" Employee ID "<<empID<<" doesn't exist"<<endl<<" Press Enter to go to Main Menu"<<endl;
        fflush(stdin);
        gets(endFrontScreen);
        system("cls");
        return;
    }

    if(checkPass){
        cout<<" Wrong Password for Employee ID "<<empID<<endl<<" Press Enter to go to Main Menu"<<endl;
        fflush(stdin);
        gets(endFrontScreen);
        system("cls");
        return;
    }

    cout<<endl<<"----------------------------------------";
    cout<<endl<<" Enter First Name of Employee    : ";
    cin>>name;
    cout<<endl<<"----------------------------------------";
    cout<<endl<<" Enter Department                : ";
    cin>>dept;
    cout<<endl<<"----------------------------------------";
    cout<<endl<<" Enter Designation               : ";
    cin>>desg;
    cout<<endl<<"----------------------------------------";
    cout<<endl<<" Enter Employee Salary           : ";
    cin>>sal;
    cout<<endl<<"----------------------------------------";
    cout<<endl<<" Enter Employee Phone No         : ";
    cin>>phNo;
    cout<<endl<<"----------------------------------------";
    cout<<endl<<" Enter Employee Password         : ";
    cin>>pass;
    cout<<endl;

 	strcpy(temp5->name, name);
	strcpy(temp5->dept, dept);
	strcpy(temp5->desg, desg);
	strcpy(temp5->pass, pass);
	temp5->sal = sal;
	temp5->phNo = phNo;
	system("cls");
}

// Function to display from beginning by employer
void displaybegbyemployer()
{
	temp2 = head;
	if (temp2 == NULL) {
		printf("\n List is Empty\n");
		system("pause");
		system("cls");
		return;
	}

	int maxstrlenname=strlen(head->name), maxstrlendept=strlen(head->dept), maxstrlendesg=strlen(head->desg);

	while(temp2!=NULL)
    {
        if(strlen(temp2->name)>maxstrlenname){
            maxstrlenname=strlen(temp2->name);
        }
        if(strlen(temp2->dept)>maxstrlendept){
            maxstrlendept=strlen(temp2->dept);
        }
        if(strlen(temp2->desg)>maxstrlendesg){
            maxstrlendesg=strlen(temp2->desg);
        }
        temp2=temp2->next;
    }

    temp2=head;
	printf("\nLIST OF EMPLOYEE\n");
	printf("----------------------------------------------------------\n");
	cout<<"Emp ID\tName";
	for(int i=0; i<maxstrlenname-3; i++){cout<<" ";}
	cout<<"Dept";
	for(int i=0; i<maxstrlendept-3; i++){cout<<" ";}
	cout<<"Desg";
	for(int i=0; i<maxstrlendesg-3; i++){cout<<" ";}
	cout<<"Salary\tPhone No."<<endl;
	printf("----------------------------------------------------------\n");
	while (temp2 != NULL) {
		cout<<temp2->empID<<"\t";
		cout<<temp2->name;
		for(int i=0; i<maxstrlenname+1-strlen(temp2->name); i++){cout<<" ";}
		cout<<temp2->dept;
		for(int i=0; i<maxstrlendept+1-strlen(temp2->dept); i++){cout<<" ";}
		cout<<temp2->desg;
		for(int i=0; i<maxstrlendesg+1-strlen(temp2->desg); i++){cout<<" ";}
		cout<<temp2->sal<<"\t"<<temp2->phNo<<endl;
		temp2 = temp2->next;
	}
	printf("----------------------------------------------------------\n");

	// Print the count
	printf("Total Number of Employees = %d\n\n", count);
	system("pause");
    system("cls");
}

// Function to display from beginning by employee
void displaybegbyemployee()
{
	temp2 = head;
	if (temp2 == NULL) {
		printf("\n List is Empty\n");
		system("pause");
		system("cls");
		return;
	}
	int maxstrlenname=strlen(head->name), maxstrlendept=strlen(head->dept), maxstrlendesg=strlen(head->desg);
	while(temp2!=NULL)
    {
        if(strlen(temp2->name)>maxstrlenname){
            maxstrlenname=strlen(temp2->name);
        }
        if(strlen(temp2->dept)>maxstrlendept){
            maxstrlendept=strlen(temp2->dept);
        }
        if(strlen(temp2->desg)>maxstrlendesg){
            maxstrlendesg=strlen(temp2->desg);
        }
        temp2=temp2->next;
    }

    temp2=head;
	printf("\nLIST OF EMPLOYEE\n");
	printf("----------------------------------------------\n");
	cout<<"Emp ID\tName";
	for(int i=0; i<maxstrlenname-3; i++){cout<<" ";}
	cout<<"Dept";
	for(int i=0; i<maxstrlendept-3; i++){cout<<" ";}
	cout<<"Desg";
	for(int i=0; i<maxstrlendesg-3; i++){cout<<" ";}
	cout<<"Phone No."<<endl;
	printf("----------------------------------------------\n");
	while (temp2 != NULL) {
		cout<<temp2->empID<<"\t";
		cout<<temp2->name;
		for(int i=0; i<maxstrlenname+1-strlen(temp2->name); i++){cout<<" ";}
		cout<<temp2->dept;
		for(int i=0; i<maxstrlendept+1-strlen(temp2->dept); i++){cout<<" ";}
		cout<<temp2->desg;
		for(int i=0; i<maxstrlendesg+1-strlen(temp2->desg); i++){cout<<" ";}
		cout<<temp2->phNo<<endl;
		temp2 = temp2->next;
	}
	printf("----------------------------------------------\n");

	// Print the count
	printf("Total Number of Employees = %d\n\n", count);
	system("pause");
    system("cls");
}

// Function to insert at end
void insertend()
{
    struct node *current=head;
	// If DLL is empty
	if (head == NULL) {
		create();
		head = temp;
		temp1 = head;
	}

	// Else create a new node and
	// update the links
	else {
		create();
		temp1->next = temp;
		temp->prev = temp1;
		temp1 = temp;
	}
    sortList();
}

// Function to delete at end
void deleteend()
{
	struct node* temp;
	temp = head;
	if (temp == NULL) {
		printf("List is Empty\n");
        system("pause");
        system("cls");
		return;
	}
	if (temp->next == NULL) {
		printf(" %d %s %s %s %.2f %ld\n is deleted..\n\n", temp->empID, temp->name, temp->dept, temp->desg, temp->sal, temp->phNo);
		free(temp);
		head = NULL;
	}
	else {
		temp = temp1;
		temp2 = temp1->prev;
		temp2->next = NULL;
		printf(" %d %s %s %s %.2f %ld\n is deleted..\n\n", temp->empID, temp->name, temp->dept, temp->desg, temp->sal, temp->phNo);
		free(temp);
		temp1 = temp2;
	}
	count--;
	system("pause");
	system("cls");
	return;
}

// Function to delete from beginning
void deletebeg()
{
	struct node* temp;
	temp = head;
	if (temp == NULL) {
		printf("List is Empty\n");
		system("pause");
        system("cls");
		return;
	}
	if (temp->next == NULL) {
		printf(" %d %s %s %s %.2f %ld\n is deleted..\n\n", temp->empID, temp->name, temp->dept, temp->desg, temp->sal, temp->phNo);
		free(temp);
		head = NULL;
	}
	else {
		head = head->next;
		head->prev = NULL;
		printf(" %d %s %s %s %.2f %ld\n is deleted..\n\n", temp->empID, temp->name, temp->dept, temp->desg, temp->sal, temp->phNo);
		free(temp);
	}
	count--;
	system("pause");
    system("cls");
	return;
}

//Function to delete by empID
void deletebyempID()
{
    if(head==NULL){
        cout<<"List is Empty\n\n";
        system("pause");
        system("cls");
        return;
    }
    node *ptr, *temp;
    int empID;
    cout<<" Enter an Employee ID: ";
    cin>>empID;
    temp = head;
    while(temp -> empID != empID){
        temp = temp -> next;
    }
    if(temp==NULL)
    {
        printf("\nEmployee ID (%d) is not in the list.\n", empID);
    }
    else if(temp->next == NULL)
    {
        temp->prev->next = NULL;
        printf(" %d %s %s %s %.2f %ld\n is deleted..\n\n", temp->empID, temp->name, temp->dept, temp->desg, temp->sal, temp->phNo);
    }
    else
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(ptr);
        printf("%d %s %s %s %.2f %ld\n is deleted..\n\n", temp->empID, temp->name, temp->dept, temp->desg, temp->sal, temp->phNo);
    }
    count--;
    system("pause");
    system("cls");
}

// Function displaying menus
void employerDetails()
{
	int ch, n, i, ch1=0, ch2=0;
	temp = temp1 = NULL;

	while (1) {
        if(pass=="1234"){

            printf("\n                < < < < Employee Management System > > > >\n");
            printf("                               For Employer\n\n");
            printf("                ===========================================\n");
            printf("               | |                                       | |\n");
            printf("               | |             MAIN MENU                 | |\n");
            printf("               | |                                       | |\n");
            printf("               | |  1. Insert n number of Data           | |\n");
            printf("               | |  2. View List of Employees            | |\n");
            printf("               | |  3. View Employee Details             | |\n");
            printf("               | |  4. Modify Existing Employee Details  | |\n");
            printf("               | |  5. Add New Employee Details          | |\n");
            printf("               | |  6. Remove an Employee Details        | |\n");
            printf("               | |  7. Go Back to Login Page             | |\n");
            printf("               | |  8. Exit                              | |\n");
            printf("               | |                                       | |\n");
            printf("               | |                                       | |\n");
            printf("                ===========================================\n\n");
            printf("               Enter The Option: ");
            fflush(stdin);

            scanf("%d", &ch);
            system("cls");
            // Switch statements begins
            switch (ch) {
            case 1:
                printf("\n Enter Number of Employees:");
                scanf("%d", &n);
                for (i = 0; i < n; i++,q++){
                    system("cls");
                    cout<<"ENTER DATA FOR EMPLOYEE "<<q<<endl<<endl;
                    insertend();
                }
                break;
            case 2:
                displaybegbyemployer();
                break;
            case 3:
                showdatabyempIDbyemployer();
                break;
            case 4:
                modifydatabyemployer();
                break;
            case 5:
                insertend();
                break;
            case 6:
                printf("\n\n\n                ===========================================\n");
                printf("               | |                                       | |\n");
                printf("               | |             MAIN MENU                 | |\n");
                printf("               | |                                       | |\n");
                printf("               | |  1. Delete Data at Start              | |\n");
                printf("               | |  2. Delete Data at End                | |\n");
                printf("               | |  3. Delete Data by Employee ID        | |\n");
                printf("               | |  4. Back to Main Menu                 | |\n");
                printf("               | |                                       | |\n");
                printf("               | |                                       | |\n");
                printf("                ===========================================\n\n");
                printf("               Enter The Option: ");


                cin>>ch2;

                system("cls");

                do{
                    if(ch2==1){
                        deletebeg();
                    }
                    else if (ch2==2){
                        deleteend();
                    }
                    else if (ch2==3){
                        deletebyempID();
                    }
                    else if (ch2==4){
                        employerDetails();
                    }
                    else{
                        ch2=0;
                        cout<<"\n               This option doesn't exist.\n\n";
                        cout<<printf("               Enter The Option: ");
                        cin>>ch2;
                    }
                }
                while(!ch2);
                break;
            case 7:
                fflush(stdin);
                login();
            case 8:
                exit(0);
            default:
                printf("Wrong Choice\n");
            }
        }
        else{

            printf("\n                < < < < Employee Management System > > > >\n");
            printf("                               For Employee\n\n");
            printf("                ===========================================\n");
            printf("               | |                                       | |\n");
            printf("               | |             MAIN MENU                 | |\n");
            printf("               | |                                       | |\n");
            printf("               | |  1. View List of Employees            | |\n");
            printf("               | |  2. View Employee Details             | |\n");
            printf("               | |  3. Modify Existing Employee Details  | |\n");
            printf("               | |  4. Go Back to Login Page             | |\n");
            printf("               | |  5. Exit                              | |\n");
            printf("               | |                                       | |\n");
            printf("               | |                                       | |\n");
            printf("                ===========================================\n\n");
            printf("               Enter The Option: ");
            fflush(stdin);

            scanf("%d", &ch);
            system("cls");

            // Switch statements begins
            switch (ch) {
            case 1:
                displaybegbyemployee();
                break;
            case 2:
                showdatabyempIDbyemployee();
                break;
            case 3:
                modifydatabyemployee();
                break;
            case 4:
                fflush(stdin);
                login();
                break;
            case 5:
                exit(0);
            default:
                printf("Wrong Choice\n");
            }
        }
	}
}

//Login function
void login()
{
    char ch;
    pass="";
    cout<<endl<<endl<<endl<<endl<<endl<<"                                User Login"<<endl<<"                                Enter Your Password : ";
    ch = _getch();
    while(ch != 13){
        pass.push_back(ch);
        cout << '*';
        ch = _getch();
    }
    if(pass == "1234" || pass == "0000"){

        cout<<endl<<"                                Access Granted"<<endl<<endl<<endl<<"                                ";
        system("pause");
        system("cls");
        // Function Call
        employerDetails();
    }
    else{
        cout<<endl<<"                                Access Aborted"<<endl<<endl<<endl;
        cout<<"                                Press any key to try again . . . ";
        pass="";
        getch();
        system("cls");
        login();
    }

}

// Driver Code
int main()
{
    char endFrontScreen[2];

    printf("\n");
    printf("                   _____                    _                  _   \n");
    printf("                  |  _  |   ___    ___     |_|   ___    ___   | |_ \n");
    printf("                  |   __|  |  _|  | . |    | |  | -_|  |  _|  |  _|\n");
    printf("                  |__|     |_|    |___|   _| |  |___|  |___|  |_|  \n");
    printf("                                         |___|                     \n\n");
    printf("                                -` :/:/+/::+:+/--.                \n");
    printf("                             :-:o. --.:-..:--.-/oo:+`.`           \n");
    printf("                         `/: --:..-----/so:-----.-.:./:-.         \n");
    printf("                       .::-:-.--------ososs/--------..-+-/.       \n");
    printf("                     .::/`.---------:+syooyoo:---------..:s:      \n");
    printf("                   `::-..----------/ooosooyoys+:---------.. ./`   \n");
    printf("                  `/--`-----------/soooosoyosso+-----------.-:/`  \n");
    printf("                 `:--`------------ooooossoyoyooo------------.-/:` \n");
    printf("                 :/:.-------------/ssssysyssysso-------------.:`- \n");
    printf("                `+o-.--------------ossososososs/-------------..++`\n");
    printf("                .--`----------------+++++++o++----------------`:+-\n");
    printf("                :::`-------------:-:/:s+oooo+/:-:-------------`:+:\n");
    printf("                :::`------------+//oo:sooooo:oo//+------------`/-+\n");
    printf("                :/-`-----------:o:oo/+sso++o/ooo:o:-----------`/--\n");
    printf("                /+-`-----------/o:oo/+osooos/+oo:o/-----------`::.\n");
    printf("                `/:.`----------:o:oo/+ossoso:ooo:o:----------`./-`\n");
    printf("                 ./o`.----------/+/oo-+ooss+-oo/+/----------..o:: \n");
    printf("                  .:/..----------:-:+:+sssy+/+-::----------.`-:-  \n");
    printf("                       `-------------/:+yyy+/-------------`   -   \n");
    printf("                         .------------../+o-------------.         \n");
    printf("                           .-/++:--:/+//:::///:-----/+.           \n");
    printf("                            +hhhh/:yhhhy::+hhhh+---.+y            \n");
    printf("                            /hhhy-.shhhs:-/yhhh+`  :yy            \n");
    printf("                             `::/:  .::o`  `-//o.oyhhhoooo:       \n");
    printf("                              yhh/  -hhh.   +hhs `/hhy````        \n");
    printf("                          `::`yhh/  .hhh.   +hhs  /hhy -/:`       \n");
    printf("                          ohh-yhh-  .hhh.   +hhy  -hhh`yhh-       \n");
    printf("                          `:/-o+-   `:::`   .::-   `://-:.        \n");
    printf("                                                                  \n\n");
    printf("                          ______        __  ___        _____      \n");
    printf("                         / ____/       /  |/  /       / ___/      \n");
    printf("                        / __/         / /|_/ /        \\__ \\     \n");
    printf("                       / /___   _    / /  / /  _     ___/ /       \n");
    printf("                      /_____/  (_)  /_/  /_/  (_)   /____/        \n\n");
    printf("                  E M P L O Y E E   M A N A G E M E N T   S Y S T E M");
    printf("                                                                  \n");
    printf("                                                                  \n");
    printf("                                                                  \n");
    printf("                               P r o j e c t  B y :               \n");
    printf("                                                                  \n");
    printf("          Sankalp Dwivedi | Nikhil Varshney | Saksham Singhal | Ayush Raj     \n");
    printf("                                                                  \n");

    gets(endFrontScreen);
    system("cls");

    login();

	return 0;
}


