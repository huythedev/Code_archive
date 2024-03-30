if(st[0] == 'S') {
            std::cout << table[x1][y1] + table[x2][y2] << ln;
        }
        else {
            std::cout << std::max(table[x1][y1], table[x2][y2]) << ln;
        }