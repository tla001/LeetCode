/*
 * MyDC.h
 *
 *  Created on: 2017Äê3ÔÂ24ÈÕ
 *      Author: tla001
 */

#ifndef INC_MYDC_H_
#define INC_MYDC_H_

#include "Include.h"
#include <limits>
class MyDC {
public:
	/*
	 * pow(x,n)
	 */
	double mypow(double x, int n) {
		if (n == 0)
			return 1.0;
		if (abs(x) < numeric_limits<double>::epsilon()) {
			return 0.0;
		}
		double half = mypow(x, n / 2);
		if (n % 2 == 0)
			return half * half;
		else if (n > 0)
			return half * half * x;
		else
			return half * half / x;
	}
};

#endif /* INC_MYDC_H_ */
