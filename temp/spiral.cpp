#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <map>
#include <set>
using namespace std;

struct point
{
    int x;
    int y;
};

int main()
{
    vector<struct point> vin;
    vector<struct point> vout;
    point start, end;
    start.x = 1;
    start.y = 1;
    end.x = start.x;
    end.y = start.y + 1;
    vin.push_back(start);
    vout.push_back(end);

    int H = 12, L = 15; //H为宽，L为长
    point p2_in, p2_out;
    p2_in.x = start.x + L - 1;
    p2_in.y = start.y;

    p2_out.x = end.x + L - 2;
    p2_out.y = end.y;

    vin.push_back(p2_in);
    // vout.push_back(p2_out);

    point p3_in,p3_out;
    p3_in.x = start.x + L - 1;
    p3_in.y = start.y + H - 1;

    // p3_out.x = end.x+L-2;
    // p3_out.y = end.y+H-3;

    vin.push_back(p3_in);
    // vout.push_back(p3_out);

    point p4_in,p4_out;
    p4_in.x = start.x;
    p4_in.y = start.y + H - 1;

    // p4_out.x = end.x + 1;
    // p4_out.y = end.y + H - 3;

    vin.push_back(p4_in);
    // vout.push_back(p4_out);

    point p5_in,p5_out;
    p5_in.x = start.x;
    p5_in.y = start.y + 2;

    // p5_out.x = end.x+1;
    // p5_out.y = end.y+2;

    vin.push_back(p5_in);
    // vout.push_back(p5_out);

    for (int i = 5; i < 100; i++)
    {
        point t;
        if (i % 4 == 0)
        {
            t.x = vin[i - 4].x + 2;
            t.y = vin[i - 4].y + 2;
        }
        if (i % 4 == 1)
        {
            t.x = vin[i - 4].x - 2;
            t.y = vin[i - 4].y + 2;
        }
        if (i % 4 == 2)
        {
            t.x = vin[i - 4].x - 2;
            t.y = vin[i - 4].y - 2;
        }
        if (i % 4 == 3)
        {
            t.x = vin[i - 4].x + 2;
            t.y = vin[i - 4].y - 2;
        }

        if (t.y-t.x == 1 || t.x <= 0 || t.y <= 0)
        {
            vin.push_back(t);
            break;
        }else
        {
            vin.push_back(t);
        }
        
    }

    for (int i = 1; i < vin.size(); i++)
    {
        point t,t1,t2;
        if (i % 4 == 1)
        {
            t.x = vin[i].x - 1;
            t.y = vin[i].y + 1;
        }
        if (i % 4 == 2)
        {
            t.x = vin[i].x - 1;
            t.y = vin[i].y - 1;
        }
        if (i % 4 == 3)
        {
            t.x = vin[i].x + 1;
            t.y = vin[i].y - 1;
        }
        if (i % 4 == 0)
        {
            t.x = vin[i].x + 1;
            t.y = vin[i].y + 1;
        }        


        if(t.x == vout[i- 1].x  && t.y == vout[i - 1].y){
            
        }else if(t.x < 0)
        {
            break;
        }else if(t.y < 0)
        {
            break;
        }else if ( vout[i-1].x < 0)
        {
            break;
        }else if (vout[i-1].y < 0)
        {
            break;
        }
        
        else{
            vout.push_back(t);
        }
    }

    for(int i = 0;i < vin.size();i++){
        cout<<"("<<vin[i].x<<","<<vin[i].y<<")"<<" ";
    }

    cout<<endl;
    cout<<endl;

    reverse(vout.begin(),vout.end());
    for(int i = 0;i < vout.size();i++){
        cout<<"("<<vout[i].x<<","<<vout[i].y<<")"<<" ";
    }

    system("pause");
    return 0;
}