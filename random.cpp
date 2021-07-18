#include <iostream>
#include <cstdlib>
#include <ctime>
#include <array>
#include <vector>
#include <iomanip>
using namespace std;
int main(){
    int x, y, sp_n, sp_x, sp_y;
    cin >> x >> y;
    cin >> sp_n;
    int arr[x][y];
    for(int i = 0; i < x; i++){
    	for(int j = 0; j < y; j++){
    		arr[i][j] = 0;
		}
	}
    srand (time(0));
	vector<int> n;
	for(int i = 0; i < x*y-sp_n; i++){
		n.push_back(i+1);
	}
	for(int i = 0; i < x*y-sp_n; i++){
		int j = rand() % (x*y-sp_n-i)+i;
		int t = n[i];
		n[i] = n[j];
		n[j] = t;
	}
    while(sp_n--){
         cin >> sp_x >> sp_y;
         arr[sp_x-1][sp_y-1]=-1;
    }
    int cnt = 0;
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            if(arr[i][j]==0){
            	arr[i][j] = n[cnt];
	            cnt++;
	            n.pop_back();
			}
        }
    }
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            if(arr[i][j]==-1){
            	cout << setw(3) << "X" << ' ';
			}
            else{
            	cout << setw(3) << arr[i][j] << ' ';
			}
            if(j!=y-1) cout << "|";
        }
        cout << '\n';
        if(i!=x-1) for(int j = 0; j < 5*y; j++) cout << '-';
        cout << '\n';
    }
    return 0;
}

