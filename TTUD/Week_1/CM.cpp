#include <bits/stdc++.h> 
using namespace std;
int H, W, n, h[10], w[10], visited, rs = 0;

struct note
{
    int h, w;
    note* next = 0;
    note(int _h, int _w) : h(_h), w(_w){}
} ;
note *sroot;
void f(note *root){
    note *tmp = root;
    while(tmp){
        if(rs) return;
        for(int i = 0; i < n; i++){
            if((visited & (1 << i)) > 0){
                int _h = tmp -> h, _w = tmp -> w, curr_h = _h, h_max = INT_MAX;
                // note *nextT = tmp -> next;
                note *nextT = root; 
                while(nextT != tmp){
                    if(nextT -> w > _w &&  nextT -> h > _h) h_max = min(h_max, nextT -> h);
                    nextT = nextT -> next;
                }
                nextT = nextT -> next;
                while(nextT && nextT -> w < _w + w[i]){
                    _h = max(_h, nextT -> h);
                    nextT = nextT -> next;
                }
                nextT = tmp -> next;
                h_max = min(h_max, H);
                if(_h + h[i] <= h_max && _w + w[i] <= W){
                    tmp -> h = _h + h[i];
                    nextT = tmp -> next;
                    tmp -> next = new note(_h, _w + w[i]);
                    tmp -> next -> next = nextT;
                    visited -= (1 << i);
                    if(visited == 0){
                        rs = 1;
                        return;
                    }
                    f(root);
                    tmp -> h = curr_h;
                    tmp -> next = nextT;
                    visited += (1 << i);
                }

                swap(h[i], w[i]);
                _h = tmp -> h, _w = tmp -> w, curr_h = _h, h_max = INT_MAX;
                nextT = root;
                while(nextT != tmp){
                    if(nextT -> w > _w &&  nextT -> h > _h) h_max = min(h_max, nextT -> h);
                    nextT = nextT -> next;
                }
                nextT = nextT -> next;
                while(nextT && nextT -> w < _w + w[i]){
                    _h = max(_h, nextT -> h);
                    nextT = nextT -> next;
                }
                nextT = tmp -> next;
                h_max = min(h_max, H);
                if(_h + h[i] <= h_max && _w + w[i] <= W){
                    tmp -> h = _h + h[i];
                    nextT = tmp -> next;
                    tmp -> next = new note(_h, _w + w[i]);
                    tmp -> next -> next = nextT;
                    visited -= (1 << i);
                    if(visited == 0){
                        rs = 1;
                        return;
                    }
                    f(root);
                    tmp -> h = curr_h;
                    tmp -> next = nextT;
                    visited += (1 << i);
                }
            }
        }
        tmp = tmp -> next;
    }
}

int main() 
{ 
    scanf("%d %d", &H, &W);
    scanf("%d", &n);
    visited = (1 << n) - 1;
    
    for(int i = 0; i < n; i++){
        scanf("%d %d", &h[i], &w[i]);
    }
    swap(h[n - 1], w[n - 1]);
    note *root = new note(0, 0);
    sroot = root;
    root -> next = new note(0, W);
    f(root);
    printf("%d", rs);
}