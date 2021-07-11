//
// Created by 晚风吹行舟 on 2021/7/9.
//

#include <iostream>
#include <vector>
#include "gtest/gtest.h"

using std::cout;
using std::endl;
using std::vector;

namespace example1 {
    /**
     * 1.@Spaces in Template Expressions
     */
    vector<vector<int> > v1;    // OK in each C++ version
    vector<vector<int>> v2;     // OK since C++11

    /**
     * 2.@nullptr and std::nullptr_t
     */
    int *p1 = NULL;     // 旧式
    // 旧式 #define NULL 0
    int *p2 = 0;
    // C++11 typedef decltype(nullptr) nullptr_t
    int *p3 = nullptr;

    void fun(int) {
        cout << "this is int(args) fun" << endl;
    }

    void fun(int *) {
        cout << "this is int*(args) fun" << endl;
    }

    TEST(C2Example1Test, test1) {
        example1::fun(0);
        example1::fun(NULL);
        example1::fun(nullptr);
    }

    /**
     * 3.@Automatic Type Deduction with auto
     * @早期auto
     * 早在C++98标准中就存在了auto关键字，
     * 那时的auto用于声明变量为自动变量，
     * 自动变量意为拥有自动的生命期，
     * 这是多余的，因为就算不使用auto声明，
     * 变量依旧拥有自动的生命期
     * int a = 10 与 auto int b = 10 等价
     * 此时与auto相对的是static
     * C++98中的auto多余且极少使用，
     * C++11已经删除了这一用法，
     * 取而代之的是全新的auto：变量的自动类型推断。
     */

    // 报错
    // auto' storage class specifier is not
    // permitted in C++11, and will not be
    // supported in future releases
    //    auto int j = 0;

    /**
     * @C11auto
     * Using auto is especially useful where
     * the type is a pretty long or complicated
     * expression
     */
    vector<int> v;
    // vector<int>::iterator pos.....
    auto pos = v.begin();
    // lambda
    auto l = [](int x) -> bool {
        return true;
    };

}


int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
    return 0;
}

