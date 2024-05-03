#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include <time.h>
/*
 * mergesort 
 * Divide and conquer
 * recursively cut vector into 2 sub vectors approx equal size +-1
 * until down to one element
 * On the way back up the recursive stack
 * merge vectors together by choosing the smallest element from the 
 * start of each sub vector. Use two indice variables to keep track
 * of comparison positions for each sub vector to avoid removing any
 * elements (expensive). Return when merged vector is same size 
 * as sum of two merging vectors
 * 
 */
using namespace std;

int randInt(int low, int high){
    //old method random number requires srand(...) seeding
    return  low + int( (high-low + 1.0)*rand() / (RAND_MAX+1.0));

    //newer C++11 random numbers requires #include <random>
    /*
    static random_device rd;
    static mt19937 rng(rd());
    uniform_int_distribution<int> dist(low, high);
    return dist(rng);
    */
}

vector <int> merge(const vector <int> &a, const vector <int> &b){
    uint i(0), j(0);
    uint tot = a.size() + b.size();
    vector <int> s;
    //complete the function to merge vec a and vec b into vec s
    while (s.size() != tot){
        if (a.at(i) < b.at(j)){
            s.push_back(a.at(i));
            i += 1;
        }
        else if(b.at(j)<a.at(i)){
            s.push_back(b.at(j));
            j+=1;
        }
        else if(b.at(j) == a.at(i)){
            s.push_back(b.at(j));
            j += 1;
        }
        
            
    return s;
}

void printvec(const vector <int> &v){
    cout<<endl;
    for (uint x=0; x<v.size();x++)
    {
        cout<<v[x]<<" "<<endl;
    }
    cout<<endl;
}

vector <int> mergesort(const vector <int> &a){
    if (a.size() == 1)
    {   
        return a;
    }
    vector <int>::const_iterator mid(a.begin()+a.size()/2); 
    //auto mid(a.begin()+a.size()/2); 
    //Must declare iterator mid as const_iterator since we passed vector a as const by ref
    // Or just use auto :)
    vector <int> a1(a.begin(), mid);
    vector <int> a2(mid, a.end());
    
    return //complete the rest of this line  
}
    
void save_rand_vec(string fname, int siz, int start, int end){
    ofstream f;
    f.open(fname);
    for (long x=0 ; x< siz; x++)
        f<<randInt(start, end)<<'\n';
    f.close();
}

vector <int> read_vec(string fname){
    vector <int> v;
    int x;
    ifstream f;
    f.open(fname);
    while ( f >> x )
    {
        v.push_back(x);
    }
    return v;
}
        

int main(){
    srand((unsigned)time(0));
    vector <int> v;
    vector <int> sv;
    for (int x=0 ; x< 20; x++)
        v.push_back(randInt(10,99)); //random_device is slow. C rand() is faster but less random
    //save_rand_vec("randata", 1234567, 0, 87654321); //run only once to create data (use random_device)
    //v = read_vec("randata");
    //printvec(v);
    sv=mergesort(v);
    printvec(sv);
    return 0;
}

