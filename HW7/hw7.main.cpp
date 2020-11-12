#include <iostream>
#include "hw7.sea.h"

using namespace std;

int main() {
    Sea S;
    cout << "beginning:" << endl;
    S.Print();

    S.SimulateOneStep();
    cout << endl << endl << "after 1 step:" << endl;
    S.Print();

    S.SimulateOneStep();
    cout << endl << endl << "after 2 steps:" << endl;
    S.Print();


    for (int i = 0; i < 8; i++) S.SimulateOneStep();
    cout << endl << endl << "after 10 steps:" << endl;
    S.Print();

    return 0;
}

/*
Sample output:

beginning:
5, 45:
Age: 0 Size: 1
34, 0:
Age: 0 Size: 1
41, 67:
Age: 0 Size: 1
61, 91:
Age: 0 Size: 1
62, 64:
Age: 0 Size: 1
69, 24:
Age: 0 Size: 1
78, 58:
Age: 0 Size: 1
81, 27:
Age: 0 Size: 1


after 1 step:
5, 46:
Age: 1 Size: 1.2
35, 0:
Age: 1 Size: 1.2
41, 67:
Age: 0 Size: 1
42, 67:
Age: 1 Size: 1.2
60, 91:
Age: 1 Size: 1.2
62, 64:
Age: 0 Size: 1
62, 65:
Age: 1 Size: 1.2
70, 24:
Age: 1 Size: 1.2
78, 57:
Age: 1 Size: 1.2
81, 28:
Age: 1 Size: 1.2


after 2 steps:
5, 47:
Age: 2 Size: 1.392
36, 0:
Age: 2 Size: 1.392
41, 66:
Age: 1 Size: 1.2
42, 67:
Age: 0 Size: 1
42, 68:
Age: 2 Size: 1.392
60, 90:
Age: 2 Size: 1.392
61, 64:
Age: 1 Size: 1.2
62, 64:
Age: 0 Size: 1
63, 65:
Age: 2 Size: 1.392
70, 23:
Age: 2 Size: 1.392
70, 24:
Age: 0 Size: 1
78, 57:
Age: 0 Size: 1
79, 57:
Age: 2 Size: 1.392
82, 28:
Age: 2 Size: 1.392


after 10 steps:
36, 0:
Age: 2 Size: 1.392
37, 0:
Age: 0 Size: 1
39, 0:
Age: 2 Size: 1.392
Age: 0 Size: 1
39, 1:
Age: 4 Size: 1.73096
39, 66:
Age: 0 Size: 1
Age: 2 Size: 1.392
Age: 3 Size: 1.57018
39, 67:
Age: 3 Size: 1.57018
39, 68:
Age: 1 Size: 1.2
Age: 0 Size: 1
Age: 2 Size: 1.392
39, 69:
Age: 2 Size: 1.392
40, 66:
Age: 0 Size: 1
Age: 1 Size: 1.2
Age: 1 Size: 1.2
40, 67:
Age: 0 Size: 1
40, 68:
Age: 5 Size: 1.87276
Age: 5 Size: 1.87276
40, 69:
Age: 0 Size: 1
Age: 0 Size: 1
40, 70:
Age: 5 Size: 1.87276
41, 65:
Age: 0 Size: 1
41, 66:
Age: 0 Size: 1
Age: 0 Size: 1
41, 67:
Age: 0 Size: 1
41, 68:
Age: 4 Size: 1.73096
Age: 0 Size: 1
42, 65:
Age: 2 Size: 1.392
Age: 0 Size: 1
42, 66:
Age: 1 Size: 1.2
Age: 3 Size: 1.57018
42, 67:
Age: 2 Size: 1.392
42, 68:
Age: 1 Size: 1.2
43, 65:
Age: 2 Size: 1.392
Age: 4 Size: 1.73096
43, 66:
Age: 0 Size: 1
Age: 0 Size: 1
44, 67:
Age: 3 Size: 1.57018
57, 89:
Age: 1 Size: 1.2
58, 89:
Age: 0 Size: 1
Age: 2 Size: 1.392
58, 90:
Age: 10 Size: 2.32234
Age: 1 Size: 1.2
Age: 1 Size: 1.2
58, 91:
Age: 0 Size: 1
Age: 0 Size: 1
59, 63:
Age: 2 Size: 1.392
59, 64:
Age: 1 Size: 1.2
Age: 7 Size: 2.10012
59, 65:
Age: 4 Size: 1.73096
59, 88:
Age: 2 Size: 1.392
59, 90:
Age: 3 Size: 1.57018
Age: 0 Size: 1
59, 91:
Age: 0 Size: 1
59, 92:
Age: 2 Size: 1.392
59, 93:
Age: 2 Size: 1.392
60, 65:
Age: 1 Size: 1.2
60, 66:
Age: 0 Size: 1
60, 67:
Age: 2 Size: 1.392
60, 88:
Age: 0 Size: 1
Age: 3 Size: 1.57018
60, 89:
Age: 0 Size: 1
60, 90:
Age: 1 Size: 1.2
Age: 3 Size: 1.57018
60, 92:
Age: 0 Size: 1
Age: 1 Size: 1.2
61, 63:
Age: 0 Size: 1
Age: 0 Size: 1
Age: 1 Size: 1.2
61, 64:
Age: 1 Size: 1.2
Age: 2 Size: 1.392
Age: 0 Size: 1
Age: 2 Size: 1.392
61, 66:
Age: 2 Size: 1.392
61, 67:
Age: 7 Size: 2.10012
61, 91:
Age: 0 Size: 1
61, 92:
Age: 1 Size: 1.2
62, 63:
Age: 7 Size: 2.10012
Age: 1 Size: 1.2
62, 64:
Age: 0 Size: 1
Age: 6 Size: 1.9955
62, 65:
Age: 0 Size: 1
Age: 3 Size: 1.57018
62, 91:
Age: 1 Size: 1.2
63, 62:
Age: 2 Size: 1.392
63, 63:
Age: 0 Size: 1
63, 64:
Age: 0 Size: 1
Age: 2 Size: 1.392
63, 65:
Age: 2 Size: 1.392
Age: 3 Size: 1.57018
63, 66:
Age: 3 Size: 1.57018
Age: 0 Size: 1
63, 92:
Age: 3 Size: 1.57018
64, 62:
Age: 3 Size: 1.57018
Age: 1 Size: 1.2
64, 63:
Age: 0 Size: 1
Age: 4 Size: 1.73096
64, 64:
Age: 1 Size: 1.2
Age: 1 Size: 1.2
Age: 4 Size: 1.73096
64, 65:
Age: 1 Size: 1.2
64, 66:
Age: 2 Size: 1.392
Age: 2 Size: 1.392
64, 67:
Age: 5 Size: 1.87276
65, 64:
Age: 1 Size: 1.2
65, 65:
Age: 2 Size: 1.392
Age: 1 Size: 1.2
65, 66:
Age: 0 Size: 1
66, 65:
Age: 6 Size: 1.9955
67, 21:
Age: 6 Size: 1.9955
68, 23:
Age: 1 Size: 1.2
68, 27:
Age: 5 Size: 1.87276
69, 23:
Age: 0 Size: 1
Age: 0 Size: 1
69, 24:
Age: 3 Size: 1.57018
Age: 0 Size: 1
Age: 1 Size: 1.2
69, 25:
Age: 4 Size: 1.73096
69, 27:
Age: 0 Size: 1
70, 24:
Age: 0 Size: 1
70, 25:
Age: 4 Size: 1.73096
71, 24:
Age: 3 Size: 1.57018
72, 24:
Age: 3 Size: 1.57018
76, 57:
Age: 1 Size: 1.2
76, 58:
Age: 3 Size: 1.57018
77, 56:
Age: 0 Size: 1
Age: 5 Size: 1.87276
77, 57:
Age: 1 Size: 1.2
Age: 1 Size: 1.2
Age: 0 Size: 1
77, 58:
Age: 2 Size: 1.392
Age: 3 Size: 1.57018
Age: 0 Size: 1
77, 59:
Age: 4 Size: 1.73096
Age: 1 Size: 1.2
Age: 2 Size: 1.392
77, 60:
Age: 3 Size: 1.57018
78, 55:
Age: 0 Size: 1
Age: 7 Size: 2.10012
78, 56:
Age: 2 Size: 1.392
78, 57:
Age: 3 Size: 1.57018
Age: 2 Size: 1.392
78, 58:
Age: 2 Size: 1.392
Age: 2 Size: 1.392
Age: 1 Size: 1.2
Age: 7 Size: 2.10012
78, 59:
Age: 3 Size: 1.57018
Age: 5 Size: 1.87276
Age: 2 Size: 1.392
78, 60:
Age: 1 Size: 1.2
Age: 0 Size: 1
79, 28:
Age: 7 Size: 2.10012
79, 29:
Age: 2 Size: 1.392
79, 30:
Age: 1 Size: 1.2
79, 55:
Age: 3 Size: 1.57018
79, 57:
Age: 1 Size: 1.2
Age: 0 Size: 1
Age: 1 Size: 1.2
Age: 1 Size: 1.2
79, 58:
Age: 1 Size: 1.2
Age: 0 Size: 1
Age: 2 Size: 1.392
Age: 2 Size: 1.392
Age: 1 Size: 1.2
Age: 1 Size: 1.2
79, 59:
Age: 2 Size: 1.392
Age: 4 Size: 1.73096
Age: 0 Size: 1
Age: 0 Size: 1
80, 27:
Age: 6 Size: 1.9955
80, 58:
Age: 3 Size: 1.57018
80, 60:
Age: 2 Size: 1.392
Age: 10 Size: 2.32234
80, 61:
Age: 0 Size: 1
81, 27:
Age: 0 Size: 1
82, 26:
Age: 0 Size: 1
Age: 0 Size: 1
Age: 2 Size: 1.392
82, 27:
Age: 1 Size: 1.2
Age: 3 Size: 1.57018
82, 56:
Age: 6 Size: 1.9955
83, 26:
Age: 1 Size: 1.2
83, 27:
Age: 3 Size: 1.57018
Age: 0 Size: 1
84, 57:
Age: 1 Size: 1.2
*/
