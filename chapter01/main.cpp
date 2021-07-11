//
// Created by 晚风吹行舟 on 2021/7/8.
// 参数数量不定的模板
//

#include <iostream>
#include "gtest/gtest.h"

using std::cout;
using std::endl;

namespace example1 {
    /**
     * 方便的完成函数的recursive
     * 同时还可以很方便的完成recursive inheritance
     *
     * 在主函数的函数体中并没有设置结束条件，
     * 因此需要重载print函数，用来结束最后一次递归调用
     *
     * 2. 3. 同时存在编译器会选择2.
     */

    // 1.递归结束函数
    void print() {}

    // 2.主函数
    template<typename T, typename... Types>
    void print(const T &firstArg, const Types &... args) {
        cout << firstArg << endl;
        // 递归调用
        print(args...);
    }

    // 3.
    template<typename ... Types>
    void print(const Types &... args) {
        cout << "this is all Types (3)" << endl;
    }

}

namespace mine1 {
    void SumUp(double &res) {}

    template<typename T, typename... Types>
    void SumUp(double &res, const T &firstArg, const Types &... args) {
        res += firstArg;
        SumUp(res, args...);
    }

}

TEST(C1Example1Test, test1) {
    cout << __cplusplus;
}

TEST(C1Example1Test, test2) {
    example1::print(1.4, 2, "123");
}

TEST(C1Mine1Test, test1) {
    double res = 0;
    mine1::SumUp(res,2,2.5f,2.50,3);
    cout << res;
}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
    return 0;
}

