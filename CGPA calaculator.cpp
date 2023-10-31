#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

//function to convert grade into points
double gradeToPoints(char grade) {
    switch (grade) {
        case 'A': return 4.0;
        case 'B': return 3.0;
        case 'C': return 2.0;
        case 'D': return 1.0;
        case 'F': return 0.0;
        default:  return -1.0;  // for Invalid grade
    }
}

//main function
int main() {
    int numofCourses;
    cout << "Enter number of courses: ";
    cin >> numofCourses;

    vector<int> credits(numofCourses);
    vector<char> grades(numofCourses);

    // Input course credits and grades
    for (int x = 0; x < numofCourses; x++) {
        cout << "Enter credits for course " << x + 1 << ": ";
        cin >> credits[x];

        cout << "Enter grade for course " << x + 1 << " (A, B, C, D, F): ";
        cin >> grades[x];
    }

    double totalCredits = 0.0;
    double totalGradePoints = 0.0;

    // Calculate semester GPA and CGPA
    for (int x = 0; x < numofCourses; x++) {
        double pointofcourse = gradeToPoints(grades[x]);
        
        if (pointofcourse == -1.0) {
            cout << "Invalid grade entered. Please use A, B, C, D, or F." << endl;
            return 1;
        }

        totalGradePoints += pointofcourse * credits[x];
        totalCredits += credits[x];
    }

    double semesterGPA = totalGradePoints / totalCredits;

    cout << "Semester GPA: " << fixed << setprecision(2) << semesterGPA << endl;
    
    double previousCGPA, previousCredits;
    cout << "Enter previous CGPA: ";
    cin >> previousCGPA;
    cout << "Enter total credits from previous semesters: ";
    cin >> previousCredits;

    // Calculate CGPA
    double newCGPA = (previousCGPA * previousCredits + semesterGPA * totalCredits) / (previousCredits + totalCredits);

    cout << "CGPA: " << fixed << setprecision(2) << newCGPA << endl;

    return 0;
}

