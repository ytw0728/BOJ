#include <stdio.h>

int main() {
	int e, m, s;
	scanf("%d %d %d", &e, &m, &s);

	e--;	m--;	s--;
	int e_tmp, m_tmp, s_tmp;

	e_tmp = m_tmp = s_tmp = 0;

	int year = 1;
	while ( e_tmp != e || m_tmp != m || s_tmp != s ) {
		e_tmp++;	m_tmp++;	s_tmp++;

		year++;

		e_tmp %= 15;
		m_tmp %= 28;
		s_tmp %= 19;
	}


	printf("%d", year);
	return 0;
}