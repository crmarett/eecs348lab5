#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>
using namespace std;

float arr_avg(int i, float c[]){
    float sum=0;
    for (int j = 0;j<6;j++) sum+=c[i+j];
    return sum/6;
}


void report(float c[], string nums[]){
    string months[13] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    
    cout << "Monthly Sales Report for 2022:\n" << endl;
    cout << left << setw(15) << "Month" << "Sales\n" << endl;
    for (int i = 0;i<12;i++){
    //months[i].length() >= 8 ? cout << months[i] << "\t$" << nums[i]<< endl : cout << months[i] << "\t\t$" << nums[i]<< endl;
    cout  << left << setw(15) << months[i]  << "$" << nums[i]<< endl; 
    }

    int  min_index = 0, max_index = 0;
    float sum = 0, max = 0, min = 1000000;
    for (int j = 0;j<12;j++){
        if (c[j]< min){
	min_index = j;
	min = c[j];
	}
	if (c[j]> max) {
	max = c[j];
	max_index = j;
	}
	sum += c[j];
	}
    cout << "\n\n";
    cout << "Sales Summary:\n" << endl;
    cout << "Minimum Sales:\t$" << nums[min_index] << "\t(" << months[min_index] << ")" << endl;
    cout << "Maximum Sales:\t$" << nums[max_index] << "\t(" << months[max_index] << ")" << endl;
    cout << "Average Sales:\t$" << setprecision(7) << sum/12<< endl;
    cout << "\n\n";

    cout << "Six-Month Moving Average Report:\n";
    for (int k = 0;k<7;k++){
        cout <<left << setw(15) <<  months[k] << "-  " <<  left << setw(12) << months[k+5]  << "$" << setprecision(7) << arr_avg(k, c) << endl;
    }


    cout << "\n\n";
    cout << "Sales Report (Highest to Lowest):\n";
    cout << left << setw(12) <<"\n  Month" << "   Sales\n" << endl;
    float last_max = max, track = 0;
    int order[12];
    order[0] = max_index;
    for (int l = 0; l<11;l++){
        for (int x = 0;x<12; x++){
	    if ((c[x]<last_max) && (c[x]>track)){
		track= c[x];
	    	max_index = x;
	    }
	    }
	last_max = track;
	track = 0;
	order[l+1] = max_index;
    }
    for (int i = 0;i<12;i++) cout << left << setw(12) << months[order[i]] << "$" << nums[order[i]]<<endl;
}


int main(int argc, char* argv[]){
    ifstream inFile;
    inFile.open("sales.txt");
    string line, nums[13];
    float c[12];
    int i = 0;

    while (getline(inFile, line)){
	nums[i] = line;
	c[i] = stof(line);
        i++;	
    }
    inFile.close();
    report(c, nums); 
    return 0;
}
