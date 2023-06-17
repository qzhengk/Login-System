#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Data Structures
struct student {
	char student_id[50];
	char student_pass[50];
	char student_name[50];
	char student_tp[50];
	char new_student[50];
	char new_student_tp[50];
};

struct tutor {
	char tutor_id[50];
	char tutor_pass[50];
	char new_tutor_id[100];
	char tutor_name[100];
	char new_tutor_protitle[100];
};

struct admin {
	char admin[50];
	char admin_id[50];
	char admin_pass[50];
};

struct session {
	char code[50];
	char title[100];
	char day[50];
	char time[50];
	char location[50];
	char tt_code[50];
	char tutor_name[100];
};

struct user {
	char role[20];
	char username[100];
	char password[100];
};
//Menu function of the three user , admin , tutor, student
void admin_menu();
void tutor_menu();
void student_menu();
//Admin functions
void addsession();
void addtutor();
void addstudent();
void admin_enrolstudent();
//Student enrol function
void enrolstudent();
//Function for showing the data
int showsession();
int showtutortable();
int showstudentsession();
int showstudenttable();
//login menu table
int login_menu();


int tables() {
	//create default table
	//if can't read the file, then create the file
	//if file is not there then print error, if exist then print data
	int i;
	int j;
	//creating default data for programmingcafe txt file
	if (fopen("programmingcafe.txt", "r") == NULL) {
		FILE* cafe = fopen("programmingcafe.txt", "w");
		if (cafe == NULL) {
			printf("ERROR...");
			return 0;
		}
		else {
			char table[10][7][50] = {
		   {"PYP101", "Python Programming", "Saturday", "9:00am","C-01-01","T01"},
		   {"JAV102", "Java Programming", "Sunday", "9:00am","C-01-02","T02"},
		   {"CPL103","C Programming", "Saturday","2:00pm", "C-01-03", "T03"},
		   {"WEB104", "Web Development", "Sunday", "2:00pm","C-01-04","T04"},
		   {"CSP105","C Sharp Programming","Monday","7:00pm","C-01-05","T05"}
			};

			//printing session table into txt file
			//i = row, j = column
			for (i = 0; i < 5; i++) {
				for (j = 0; j < 6; j++) {
					fprintf(cafe, "%s,", table[i][j]);
				}
				fprintf(cafe, "\n");
			}
		}
		fclose(cafe);
	}

	//creating default data for tutor table into txt file
	if (fopen("tutortable.txt", "r") == NULL) {
		FILE* tutortable = fopen("tutortable.txt", "w");
		if (tutortable == NULL) {
			printf("ERROR...");
			return 0;
		}
		else {
			char tutortables[10][6][50] = {
			  {"T01", "Albert", "Python Programming", "Saturday", "9:00am", "C-01-01"},
			  {"T02", "Amad", "Java Programming", "Sunday", "9:00am", "C-01-02"},
			  {"T03", "Steve", "C Programming", "Saturday", "2:00pm", "C-01-03"},
			  {"T04", "Alex", "Web Development", "Sunday", "2:00pm", "C-01-04"},
			  {"T05", "Adrian", "C Sharp Programming", "Monday", "7:00pm", "C-01-05"}
			};
			for (i = 0; i < 5; i++) {
				for (j = 0; j < 6; j++) {
					fprintf(tutortable, "%s,", tutortables[i][j]);
				}
				fprintf(tutortable, "\n");
			}
		}
		fclose(tutortable);
	}
	//creating default data for login details to txt file
	if (fopen("login.txt", "r") == NULL) {
		FILE* logindetails = fopen("login.txt", "w");
		if (logindetails == NULL) {
			printf("ERROR...");
			return 0;
		}
		else {
			char login_info[9][3][50] = {
				//role || username || password//
				{"admin", "qzheng", "qzheng"},
				{"tutor", "albert", "albert123"},
				{"tutor", "amad", "amad123"},
				{"tutor", "alex", "alex123"},
				{"tutor", "adrian", "adrian123"},
				{"student", " wongxuen", " wongxuen123"},
				{"student", "sebastian", "sebastian123"},
				{"student", "nicholas", "nichloas123"},
				{"student", "dickson", "dickson123"},
			};
			for (i = 0; i < 9; i++) {
				for (j = 0; j < 3; j++) {
					fprintf(logindetails, "%s,", login_info[i][j]);
				}
				fprintf(logindetails, "\n");
			};
		}
		fclose(logindetails);
	}
	//creating student information table into txtt file
	if (fopen("studenttable.txt", "r") == NULL) {
		FILE* studenttable = fopen("studenttable.txt", "w");
		if (studenttable == NULL) {
			printf("ERROR...");
			return 0;
		}
		else {
			char student_info[10][2][50] = {
				{"TP066457", "wongxuen",},
				{"TP066458", "Sebastian"},
				{"TP066459", "Nichloas"},
				{"TP066460", "Dickson"},
				{"TP012345", "Terence"}
			};
			for (i = 0; i < 5; i++) {
				for (j = 0; j < 2; j++) {
					fprintf(studenttable, "%s,", student_info[i][j]);
				}
				fprintf(studenttable, "\n");
			}

			fclose(studenttable);
		}
	}
	//creating enrolsession table into txt file for information aboutt student session
	if (fopen("enrolsession.txt", "r") == NULL) {
		FILE* enrolsession = fopen("enrolsession.txt", "w");
		if (enrolsession == NULL) {
			printf("ERROR...");
			return 0;
		}
		else {
			char enrol_sess[10][6][50] = {
				{"TP066457", "PYP101", "T01", "C-01-01", "9:00am", "Saturday"},
				{"TP066458", "JAV102", "T02", "C-01-02", "9:00am", "Sunday"},
				{"TP066459", "CPL103", "T03", "C-01-03", "2:00pm", "Saturday"},
				{"TP012345", "WEB104", "T04", "C-01-04", "2:00pm", "Sunday"},
				{"TP066460", "CSP105", "T05", "C-01-05", "7:00pm", "Monday"},
			};
			for (i = 0; i < 5; i++) {
				for (j = 0; j < 6; j++) {
					fprintf(enrolsession, "%s,", enrol_sess[i][j]);
				}
				fprintf(enrolsession, "\n");
			}
			fclose(enrolsession);
		}

	}
	return 0;
}

int login_menu() {

	char username[50];
	char password[50];
	int verification = 0;
	int respond = 0;
	struct user users;
	FILE* logindetails = fopen("login.txt", "r");
	printf("\n============================================================");
	printf("\n\t\t\t WELCOME");
	printf("\n============================================================");
	printf("\n\nPlease enter your username: ");
	scanf("%s", username);
	printf("\nPlease enter your password: ");
	scanf("%s", password);
	//ask for input
	//compare input given by user and data in logindetails
	while (fscanf(logindetails, "%[^,],%[^,],%[^,],\n", users.role, users.username, users.password) != EOF) {
		if (strcmp(users.username, username) == 0 && strcmp(users.password, password) == 0) {
			verification = 1;
			break;
		}
	}
	//if verified then compare the role of user
	//if admin/tutor/student then will be directed to their respective menu, else error message will prompt out
	if (verification == 1) {
		fclose(logindetails);
		if (strcmp(users.role, "admin") == 0) {
			admin_menu();
		}
		else if (strcmp(users.role, "tutor") == 0) {
			tutor_menu();
		}
		else if (strcmp(users.role, "student") == 0) {
			student_menu();
		}

	}
	else {
		printf("\n\nWRONG USERNAME OR PASSWORD...\n\n");
		login_menu();
	}

	return verification;
}

int main() {
	tables();
	login_menu();
	return 0;
}

void admin_menu()   {
	//prompt user for their choice of action
	//after choosing will then be directed to the respective functions
	int admin_choice;

	
	printf("\n============================================================");
	printf("\n\t\t    ADMIN MAIN MENU");
	printf("\n============================================================");
	do {
		printf("\n\n[1] Add tutor\n[2] Add new Session\n[3] Register Student\n[4] Enrol Student\n[5] Show Session listing\n[6] Show Student Session Listing\n[7] Show Tutor Listing \n[8] Exit\n");
		printf("\n\nPlease enter your choice of action: ");
		scanf("%d", &admin_choice);
		switch (admin_choice) {
		case 1:
			addtutor();
			break;

		case 2:
			addsession();
			break;

		case 3:
			addstudent();
			break;

		case 4:
			admin_enrolstudent();
			break;

		case 5:
			showsession();
			break;
		case 6:
			showstudentsession();
			break;
		case 7:
			showtutortable();
			break;
		case 8:
			printf("\n\n EXITING......\n\n");
			main();
			break;
		default:
			printf("\nInvalid Answer!!!!");
			admin_menu();
			break;
		}
	} while (admin_choice != 8);
}

void addtutor() {

	struct tutor tt;
	struct session sessions;
	int confirmation;

	FILE* logindetails = fopen("login.txt", "a");
	FILE* tutortable = fopen("tutortable.txt", "a+");
	//tutor information and login details are asked here
	getchar();
	printf("\nEnter new Tutor ID: ");
	scanf("%[^\n]", tt.new_tutor_id);
	getchar();
	printf("\nEnter new Tutor Name: ");
	scanf("%[^\n]", tt.tutor_name);
	printf("\nEnter new Tutor Password: ");
	scanf("%s", tt.tutor_pass);
	getchar();
	printf("\nEnter new Tutor session title: ");
	scanf("%[^\n]", tt.new_tutor_protitle);
	printf("\nEnter new session day: ");
	scanf("%s", sessions.day);
	printf("\nEnter new Tutor session time: ");
	scanf("%s", sessions.time);
	printf("\nEnter new Tutor session location: ");
	scanf("%s", sessions.location);

	//confirmation is requested and if yes then data that the user entered will be stored in the respective txt file
	//if confirmation is no then will be redirect to the questions again
	printf("\nConfirm Tutor information.\n[1] Yes\n[2] No\nAnswer: ");
	scanf("%d", &confirmation);
	
	switch (confirmation) {
	case 1:

		while (fscanf(tutortable, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],\n", sessions.tt_code, sessions.tutor_name, sessions.title, sessions.day, sessions.time, sessions.location) != EOF) {
			if (strcmp(tt.new_tutor_id, sessions.tt_code) == 0) {
				printf("\n\nThis Tutor already exist...");
				admin_menu();
			}
		}

		fprintf(tutortable, "%s,%s,%s,%s,%s,%s,\n", tt.new_tutor_id, tt.tutor_name, tt.new_tutor_protitle, sessions.day, sessions.time, sessions.location);
		fprintf(logindetails, "tutor,%s,%s,\n", tt.tutor_name, tt.tutor_pass);
		fclose(tutortable);
		fclose(logindetails);
		printf("\n------------- Register Successful -------------\n\n");
		break;

	case 2:
		printf("\n------------- Please re-enter Tutor information -------------");
		addtutor();
		break;
	}
		

}

void addsession() {
	struct session new_session;
	int confirmation;
	FILE* cafe = fopen("programmingcafe.txt", "a");
	if (cafe == NULL) {
		printf("No file found....");
	}

	printf("\nEnter New Session Code: ");
	scanf("%s", new_session.code);
	printf("\nEnter New Session Title: ");
	getchar();
	scanf("%[^\n]", new_session.title);
	printf("\nEnter New Session Day: ");
	scanf("%s", new_session.day);
	printf("\nEnter New Session Start Time: ");
	scanf("%s", new_session.time);
	printf("\nEnter New Session Location: ");
	scanf("%s", new_session.location);
	printf("\nEnter New Session Tutor Code: ");
	scanf("%s", new_session.tt_code);

	printf("\nConfirm Session information.\n[1] Yes\n[2] No\nAnswer: ");
	scanf("%d", &confirmation);

	switch (confirmation) {
	case 1:
		fprintf(cafe, "%s,%s,%s,%s,%s,%s,\n", new_session.code, new_session.title, new_session.day, new_session.time, new_session.location, new_session.tt_code);
		fclose(cafe);
		printf("\n------------- Session Added -------------");
		break;

	case 2:
		printf("\n------------- Please re-enter Session information -------------");
		addsession();
		break;
	}
	
	
}

void addstudent() {
	FILE* logindetails = fopen("login.txt", "a");
	FILE* studenttable = fopen("studenttable.txt", "a+");
	struct student students;
	int confirmation;

	printf("\nEnter Student name: ");
	scanf("%s", students.new_student);
	printf("\nEnter new Student TP Number (TPXXXXXX): ");
	scanf("%s", students.new_student_tp);
	printf("\nEnter new Student Password: ");
	scanf("%s", students.student_pass);

	printf("\nConfirm Session information.\n[1] Yes\n[2] No\nAnswer: ");
	scanf("%d", &confirmation);

	switch (confirmation) {
	case 1:

		while (fscanf(studenttable, "%[^,],%[^,],\n", students.student_tp,students.student_name) != EOF) {
			if (strcmp(students.student_tp, students.new_student_tp) == 0) {
				printf("\nThis student already exist...");
				admin_menu();
			}
		}
		fprintf(studenttable, "%s,%s,\n", students.new_student_tp, students.new_student);
		fclose(studenttable);
		printf("\n------------- Student Added -------------");

		fprintf(logindetails, "student,%s,%s,\n", students.new_student, students.student_pass);
		fclose(logindetails);
		break;

	case 2:
		printf("\n------------- Please re-enter Student information -------------");
		addstudent();
		break;
	}
	
}

void admin_enrolstudent() {
	//related file are open for read and append
	
	char tp_number[50];
	char sess_code[50];
	int authentication = 0;
	int checking = 0;
	int confirmation;
	struct student students;
	struct session sessions;
	
	FILE* studenttable = fopen("studenttable.txt", "r");
	FILE* cafe = fopen("programmingcafe.txt", "r");
	FILE* enrolsession = fopen("enrolsession.txt", "a");

	showstudenttable();
	printf("\n\nEnter student TP Number: ");
	scanf(" %s", tp_number);
	showsession();
	printf("\n\nEnter Session Code that you want to assign: ");
	scanf(" %s", sess_code);

	printf("\nConfirm Information.\n[1] Yes\n[2] No\nAnswer: ");
	scanf("%d", &confirmation);
	//string compare is used to verify the existence of the session code and student tp number
	switch (confirmation) {
	case 1:
		while (fscanf(cafe, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],\n", sessions.code, sessions.title, sessions.day, sessions.time, sessions.location, sessions.tt_code) != EOF) {
			if (strcmp(sessions.code, sess_code) == 0) {
				authentication = 1;
				break;
			}

		}

		while (fscanf(studenttable, "%[^,],%[^,],\n", students.student_tp, students.student_name) != EOF) {
			if (strcmp(students.student_tp, tp_number) == 0) {
				checking = 1;
				break;
			}

		}
		//if both exist then student session data will be uploaded to enrolsession txt file
		if (authentication && checking) {
			fprintf(enrolsession, "%s,%s,%s,%s,%s,%s,\n", tp_number, sess_code, sessions.tt_code, sessions.location, sessions.time, sessions.day);
			printf("\n ------------- Enrolled -------------");
		}
		else {
			printf("\nInvalid Session Code or Student ID! ");
			admin_enrolstudent();
		}
		break;

	case 2:
		admin_enrolstudent();
		break;
	}
	
	
	fclose(studenttable);
	fclose(cafe);
	fclose(enrolsession);
}

void enrolstudent() {

	//this file functions the same as admin_enrolstudent()
	//just that this function is for student menu
	char tp_number[50];
	char sess_code[50];
	struct student students;
	struct session sessions;
	int authentication = 0;
	int checking = 0;
	int confirmation;
	FILE* studenttable = fopen("studenttable.txt", "r");
	FILE* cafe = fopen("programmingcafe.txt", "r");
	FILE* enrolsession = fopen("enrolsession.txt", "a");

	showstudenttable();
	printf("\n\nEnter your TP Number: ");
	scanf(" %s", tp_number);
	showsession();
	printf("\n\nEnter Session Code that you want to assign: ");
	scanf(" %s", sess_code);

	printf("\nConfirm Information.\n[1] Yes\n[2] No\nAnswer: ");
	scanf("%d", &confirmation);

	switch (confirmation) {
	case 1:
		while (fscanf(cafe, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],\n", sessions.code, sessions.title, sessions.day, sessions.time, sessions.location, sessions.tt_code) != EOF) {
			if (strcmp(sessions.code, sess_code) == 0) {
				authentication = 1;
				break;
			}

		}

		while (fscanf(studenttable, "%[^,],%[^,],\n", students.student_tp, students.student_name) != EOF) {
			if (strcmp(students.student_tp, tp_number) == 0) {
				checking = 1;
				break;
			}

		}

		if (authentication && checking) {
			fprintf(enrolsession, "%s,%s,%s,%s,%s,%s,\n", tp_number, sess_code, sessions.tt_code, sessions.location, sessions.time, sessions.day);
			printf("\n ------------- Enrolled -------------");
		}
		else {
			printf("\nInvalid Session Code or Student ID! ");
			admin_enrolstudent();
		}
		break;

	case 2:
		admin_enrolstudent();
		break;
	}
	fclose(studenttable);
	fclose(cafe);
	fclose(enrolsession);
}

void tutor_menu() {
	//this is the tutor menu where after tutor login they will be directed here
	//various option are given for the tutor to select
	//after selection, they will be directed to their respective functions
	char choice;
	printf("\n============================================================");
	printf("\n\t\t    TUTOR MAIN MENU");
	printf("\n============================================================");
	do {

		printf("\n\n [V] View Session Listing.\n [T] View Student Session Listing.\n [Q] Show Tutor Table.\n [E] Exit.\n");
		printf("\n Please enter your option: ");
		scanf(" %c", &choice);
		switch (choice) {
		case 'V':
		case 'v':
			showsession();
			break;

		case 'T':
		case 't':
			showstudentsession();
			break;

		case 'Q':
		case 'q':
			showtutortable();
			break;
		case 'E':
		case 'e':

			printf("\n\nEXITING......\n\n");
			main();
			break;

		default:
			printf("\nInvalid Answer!!!");
			tutor_menu();
			break;
		}
	} while (1);
}

void student_menu() {
	//this is the student menu where after tutor login they will be directed here
	//various option are given for the student to select
	//after selection, they will be directed to their respective functions
	char choice;
	printf("\n============================================================");
	printf("\n\t\t    STUDENT MAIN MENU");
	printf("\n============================================================");
	do {
		printf("\n\n [V] View Listing.\n [S] Enrol Session.\n [T] View Student Session Listing.\n [E] Exit.\n");
		printf("\n Please enter your option: ");
		scanf(" %c", &choice);
		switch (choice) {
		case 'V':
		case 'v':
			showsession();
			break;

		case 'S':
		case 's':
			enrolstudent();
			break;
			
		case 'T':
		case 't':
			showstudentsession();
			break;

		case 'E':
		case 'e':
			printf("\n\nEXITING......\n\n");
			main();
			break;

		default:
			printf("\nInvalid Answer!!!");
			student_menu();
			break;
		}
	} while (1);
}

int showsession() {
	struct session sessions;

	printf("\n------------- Showing Listing -------------\n");
	FILE* cafe = fopen("programmingcafe.txt", "r");
	if (cafe == NULL) {
		printf("fail to read file....");
		return 1;
	}
	//print session header all 
	//print the seperator lines
	//scans programmingcafe txt file
	//each ','seperates the data and the data are stored in sessions.code and many other variables 
	//last all the data are printed with their %-20s as -20 means take up 20 empty character of the right side
	printf("===================================================================================================================================================");
	printf("\n|| \t%-20s || \t%-20s|| \t%-20s|| \t%-20s|| \t%-20s|| %-5s|| ", "Session Code", "Program Title", "Day", "Time", "Location", "Tutor Code");
	printf("\n===================================================================================================================================================");

	while (fscanf(cafe, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],\n", sessions.code, sessions.title, sessions.day, sessions.time, sessions.location, sessions.tt_code) != EOF) {
		printf("\n|| \t%-20s || \t%-20s|| \t%-20s|| \t%-20s|| \t%-20s|| %-10s|| ", sessions.code, sessions.title, sessions.day, sessions.time, sessions.location, sessions.tt_code);
	}

	fclose(cafe);
	printf("\n===================================================================================================================================================");
	return 0;
}

int showtutortable() {
	struct tutor tt;
	struct session sessions;
	int option;
	int authentication = 0;
	char id[50];
	FILE* tutortable = fopen("tutortable.txt", "r");
	if (tutortable == NULL) {
		printf("Fail to read file....");
		return 1;
	}

	printf("\nChoose your option of viewing.\n[1] All Session\n[2] Assigned Session\nAnswer: ");
	scanf("%d", &option);
	//Data is being fetched from the tutortable txt file and printed out line by line
	//while not end of file print line 1,2,3,4,5,6.....
	switch (option) {
	case 1:
		printf("\n------------- Showing Listing -------------\n");

		printf("\n=====================================================================================================================================================================");
		printf("\n|| \t%-20s || \t%-21s|| \t%-21s|| \t%-16s|| %-16s|| %-21s|| ", "Tutor Code", "Tutor Name", "Program Title", "Day", "Time", "Location");
		printf("\n=====================================================================================================================================================================");
		while (fscanf(tutortable, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],\n", sessions.tt_code, tt.tutor_name, sessions.title, sessions.day, sessions.time, sessions.location) != EOF) {
			printf("\n|| \t%-20s || \t%-20s || \t%-20s || \t%-15s || %-15s || %-20s || ", sessions.tt_code, tt.tutor_name, sessions.title, sessions.day, sessions.time, sessions.location);
		}
		printf("\n=====================================================================================================================================================================");

		break;
	case 2:
		printf("\nEnter your Tutor Code: ");
		scanf("%s", id);

		printf("\n=====================================================================================================================================================================");
		printf("\n|| \t%-20s || \t%-21s|| \t%-21s|| \t%-16s|| %-16s|| %-21s|| ", "Tutor Code", "Tutor Name", "Program Title", "Day", "Time", "Location");
		printf("\n=====================================================================================================================================================================");
		while (fscanf(tutortable, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],\n", sessions.tt_code, sessions.tutor_name, sessions.title, sessions.day, sessions.time, sessions.location) != EOF) {
			if (strcmp(sessions.tt_code, id) == 0) {
				authentication = 1;
				printf("\n|| \t%-20s || \t%-20s || \t%-20s || \t%-15s || %-15s || %-20s ||", sessions.tt_code, sessions.tutor_name, sessions.title, sessions.day, sessions.time, sessions.location);
				break;
			}
		}		
		printf("\n=====================================================================================================================================================================");


	

	}

	fclose(tutortable);

	return 0;
}

int showstudentsession() {
	struct session sessions;
	struct student students;
	int option;
	int authentication = 0;
	char answer[50];
	int i, j;
	FILE* enrolsession = fopen("enrolsession.txt", "r");
	printf("\nChoose your option of viewing.\n[1] All Session\n[2] Assigned Session\nAnswer: ");
	scanf("%d", &option);
	//Data is being fetched from the enrolsession txt file and printed out line by line
	//while not end of file print line 1,2,3,4,5,6.....
	switch (option) {
	case 1:
		printf("\n------------- Showing Listing -------------\n");

		printf("\n================================================================================================================================================================");
		printf("\n|| \t%-20s || \t%-21s|| \t%-21s|| \t%-21s|| %-16s|| %-11s|| ", "TP Number", "Session Code", "Tutor Code", "Location", "Time", "Day");
		printf("\n================================================================================================================================================================");

		while (fscanf(enrolsession, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],\n", students.student_tp, sessions.code, sessions.tt_code, sessions.location, sessions.time, sessions.day) != EOF) {
			printf("\n|| \t%-20s || \t%-20s || \t%-20s || \t%-20s || %-15s || %-10s ||", students.student_tp, sessions.code, sessions.tt_code, sessions.location, sessions.time, sessions.day);
		}
		printf("\n================================================================================================================================================================");
		break;
	case 2:
		printf("\nEnter your TP Number: ");
		scanf("%s", answer);

		printf("\n================================================================================================================================================================");
		printf("\n|| \t%-20s || \t%-21s|| \t%-21s|| \t%-21s|| %-16s|| %-11s|| ", "TP Number", "Session Code", "Tutor Code", "Location", "Time", "Day");
		printf("\n================================================================================================================================================================");

		while (fscanf(enrolsession, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],\n", students.student_tp, sessions.code, sessions.tt_code, sessions.location, sessions.time, sessions.day) != EOF) {
			if (strcmp(students.student_tp, answer) == 0) {
				printf("\n|| \t%-20s || \t%-20s || \t%-20s || \t%-20s || %-15s || %-10s ||", answer, sessions.code, sessions.tt_code, sessions.location, sessions.time, sessions.day);

			}
		}
		printf("\n================================================================================================================================================================");

		break;
	}
	fclose(enrolsession);
	return 0;

}

int showstudenttable() {
	//shows student tables for enrol session
	struct student students;
	FILE* studenttable = fopen("studenttable.txt", "r");
	if (studenttable == NULL) {
		printf("Fail to read file....");
		return 1;
	}
	printf("\n===============================================================");
	printf("\n|| \t%-20s || \t%-20s ||", "TP number", "Name");
	printf("\n===============================================================");


	while (fscanf(studenttable, "%[^,],%[^,],\n", students.student_tp, students.student_name) != EOF) {
		printf("\n|| \t%-20s || \t%-20s || ", students.student_tp, students.student_name);
	}
	printf("\n===============================================================");
	fclose(studenttable);

	return 0;
}