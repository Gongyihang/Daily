#include <iostream>
using namespace std;

class Quote
//class Quote final
{
public:
    Quote() = default;                                                                  //空的默认构造函数
    Quote(const string &book, double sales_price) : bookNo(book), price(sales_price) {} //赋值的自定义构造函数
    string isbn() const { return bookNo; };                                             //只能通过该函数访问bookNo
    virtual double net_price(size_t n) const { return n * price; };                     //定义为virtual，基类希望派生类进行覆盖的函数
    virtual ~Quote() = default;                                                         //定义为virtual，基类希望派生类进行覆盖的空的默认析构函数
    // void f3();                                                                          //f3不是虚函数，不能在派生类中进行override

private:                                                                                //不可更改的bookNo，不论派生类还是其他用户只能通过isbn函数进行访问
    string bookNo;

protected:                                                                              //基类希望派生类定义各自的price
    double price = 100;
};

class Bulk_quote : public Quote
{
public:
    Bulk_quote() = default;
    Bulk_quote(const string& book, double p, size_t qty, double disc):Quote(book,p),min_qty(qty),discount(disc){};  //初始化Quote的部分和自己的部分
    double net_price(size_t cnt) const override                                      //形参列表之后添加的override显式注明将使用哪个成员函数改写基类的虚函数
    {
        if (cnt >= min_qty)
        {
            return cnt * (1 - discount) * price;
        }
        else
        {
            return cnt * price;
        }
    };
        

private:                                                                            //基类自身的参数
    size_t min_qty = 0;
    double discount = 0.0;
};

double print_total(ostream &os, const Quote &item, size_t n)
{
    // double ret = item.net_price(n);
    double ret = item.Quote::net_price(n);
    os << "ISBN: " << item.isbn() << "#sold: " << n << " total due: " << ret << endl;
    return ret;
}

int main()
{

    Quote basic("zzz", 100);              //基类对象
    Bulk_quote bulk("sss", 100, 10, 0.6); //派生类对象
    Quote *p = &basic;                    //p指向Quote对象
    p = &bulk;                            //p指向bulk的Quote部分
    Quote &r = bulk;                      //r绑定到bulk的Quote部分

    // double undis = p->Quote::net_price(42);
    // cout<<"ISBN: "<<p->isbn()<<"#sold: "<<42<<" total due: "<<undis<<endl;
    print_total(cout, basic, 20);
    print_total(cout, *p, 20);
    print_total(cout, r, 20);

    return 0;
}