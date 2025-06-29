#include <iostream>
#include <fstream>
#include <string>


using namespace std;

struct student{

string name;
string number;
int score;



};
class manageprogram{
    private:
    student *students=new student[30];
    int count;
    int max;
    int maxnum;
    int min;
    int minnum;
    public:
        manageprogram(){
            max=0;
            count=0;
            maxnum=0;
             min=100;
             minnum=0;
        }
        ~manageprogram() {
        delete[] students;
    }
        void add(string name, string number, int score){
            if(count>=30){
                cout<<"더 이상 학생에 대한 정보를 넣을 수 없습니다."<<endl;
            }




            students[count].name=name;
            students[count].number=number;
            students[count].score=score;
            if(score>max){
                max=score;
                maxnum=count;
            }
             if(score<min){
                min=score;
                minnum=count;
            }
            count++;


        }
        
        void maxmin(){
            cout<<"highest student's name is:"<<students[maxnum].name<<endl;
             cout<<"highest student's score is:"<<max<<endl;

             cout<<"lowest student's name is:"<<students[minnum].name<<endl;
             cout<<"loweststudent's score is:"<<min<<endl;


        }

         void quicksort(student *students, int start, int end){
             if (start >= end) return;
            int left=start;
            int right=end;
            int mid=left+(right-left)/2;
            int pivot=students[mid].score;


            while(left<=right){

                while(students[left].score<pivot){
                    left++;
                }
                 while(students[right].score>pivot){
                    right--;
                }
                if(left<=right){
                    swap(students[left],students[right]);
                    left++;
                    right--;
                }



            }

            quicksort(students,start,right);
            quicksort(students,left,end);


        }


        void swap(student &a, student &b){
            student temp=b;     /* temp(b)  b(a) a(b) */
            b=a;
            a=temp;
            

            
        }

        void merge(student *arr,int start,int end){
            int mid=start+(end-start)/2;

            int n1=mid-start+1;
            int n2=end-mid;
            student *l=new student[n1];
            student *r=new student[n2];
            for(int i=0;i<n1;i++){
                l[i]=arr[start+i];



            }
             for(int i=0;i<n2;i++){
                r[i]=arr[mid+1+i];



            }
            int i=0, j=0, begin=start;


            while(i<n1&&j<n2){
                if(l[i].score<r[j].score){
                    arr[begin++]=l[i++];

                }
                else{

                    arr[begin++]=r[j++];

                }






            }   
            while(i<n1){
                arr[begin++]=l[i++];
            }
            while(i<n2){
                arr[begin++]=r[j++];
            }








        }


        void mergesort(student *arr, int start,int end){
            if(start<end){
                int mid=start+(end-start)/2;
                mergesort(arr,start,mid);
                mergesort(arr,mid+1,end);
                merge(arr,start,end);











            }



        }


        void sort(){
             mergesort(students,0,count-1);
        }
       



        void savetoFIle(){
            ofstream outFile("student_information.txt");
            if(!outFile){
                cerr<<"file is not existing"<<endl;
            }
            else{
                for(int i=0;i<count;i++){
                    outFile<<i<<endl;
                    outFile<<students[i].name<<endl;
                    outFile<<students[i].number<<endl;
                    outFile<<students[i].score<<endl;

                }


            }
            outFile.close();

        }
        void loadFromFile() {
    ifstream inFile("student_information.txt");
    if (!inFile) {
        cerr << "파일을 열 수 없습니다." << endl;
        return;
    }
    
    string dummy;  // i (인덱스) 값은 무시할 변수
    count = 0;

    while (getline(inFile, dummy)) {
          // 인덱스 줄 읽기 (0, 1, 2, ...)
        if (count >= 30) break;

        getline(inFile, students[count].name);     // 이름
        getline(inFile, students[count].number);   // 학번
        inFile >> students[count].score;           // 점수
        inFile.ignore();                           // 줄바꿈 처리
        
    }

    inFile.close();
}


};




int main(){


manageprogram *mp=new manageprogram();

mp->add("shinhyunji","23-70013199",60);
mp->add("shinusnho","23-70013199",90);
mp->add("shin","23-70013199",55);
mp->sort();
mp->savetoFIle();







delete mp;


}
