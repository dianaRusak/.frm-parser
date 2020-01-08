#include <iostream>
#include "task1.h"
int main(int argc, char** argv) {
    myFrm::Task1 frmParser;
    std::cout << frmParser.isFrm("/home/botinok/mariadb/server/mysql-test/std_data/mysql5613mysql/tables_priv.frm");
    return 0;
}
