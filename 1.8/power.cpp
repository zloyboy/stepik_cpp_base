
int power(int x, unsigned p) {
	int answer = 1;
	for(int i=0; i<p; i++) {
		answer *= x;
	}
	return answer;
}

int main()
{
	cout << power(11, 2) << endl;

	return 0;
}

