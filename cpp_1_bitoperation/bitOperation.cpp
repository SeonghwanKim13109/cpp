#include <iostream>
using namespace std;

int main() {
	/*
	��Ʈ �� ������

	AND(&) OR(|) NOT(~) XOR(^)

	 87 : 101 0111
	&53 : 011 0101
	-----------------
	      001 0101  = 16 +4 +1 = 21

	 87 : 101 0111
	|53 : 011 0101
	-----------------
	      111 0111 = 127- 8 = 119

	~53 : 0011 0101
	-----------------
		  1 100 1010  = 2�� ������ ���� -54
	 87 : 101 0111
	^53 : 011 0101
	-----------------
	      110 0010   = 64+32+2 = 98
	*/
	unsigned int x = 53;
	cout << "87 & 53 = " << (87 & 53) << endl;
	cout << "87 | 53 = " << (87 | 53) << endl;
	cout << "~53 = " << (~53) << endl;
	cout << "87 ^ 53 = " << (87 ^53) << endl;

	const int iAttack = 0x00000001;
	const int iAmor = 0x00000002;
	const int iHp = 0x00000004;
	const int iMp = 0x00000008;
	const int iCritical = 0x00000010;

	cout << iAttack << iAmor << iHp << iMp << iCritical << endl;
	//OR�� �̿��� ����ŷ
	int iBuf = iAttack | iHp | iCritical;

	//AND�� �̿��� ����ŷ 
	cout << "Attack : " << (iBuf & iAttack)<<endl;
	cout << iBuf << endl;

	//XOR�� �̿��� ����ŷ ->Ư����Ʈ ON/OFF
	cout <<(((iBuf ^= iHp)&iHp)==iHp)<<endl;
	cout << (((iBuf ^= iHp)&iHp)==iHp)<<endl;

	/*Shift ������
	 20 << 2   
	=0001 0100 << 2
	=0101 0000  = 64+16 =80; 
	(�Ǵ� 20*2^2 = 80);

	����
	20 << 3 = 160
	20 << 4 = 320 

	�ݴ��
	20 >> 2 = 5
	20 >> 3 = 2
	20 >> 4 = 1
	*/
	cout << "20<<2 = " << (20 << 2) << endl;
	cout << "20>>4 = " << (20 >> 4) << endl;

	//32bit�� ���� 16bit�� ���� 16bit
	int iHigh = 187;
	int iLow = 13560;

	int iNum = iHigh;
	iNum <<= 16;
	iNum += iLow;

	cout << "iNum = " << iNum << endl;
	
	iNum -= iLow;
	iNum |= iLow;

	cout << "iNum = " << iNum << endl;

	cout << "iHigh = " << (iNum>>16) << endl;
	cout << "iLow = " << (iNum&0xffff) << endl;
	return 0;
}