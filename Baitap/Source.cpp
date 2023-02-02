#include <iostream>
#include <string.h>
using namespace std;
// Struct
int soluong;
struct HocSinh
{
	int ID;
	char Ten[50];
	float toan, ly, hoa, dtb;
};
// Câu 1: Tạo và nhập xuất cấu trúc dữ liệu Học Sinh gồm id, name, điểm toán - lý - hóa
void NhapHS(HocSinh& HS) {
	cout << "Nhap ID HS: ";
	cin >> HS.ID;
	cin.ignore();
	cout << "Nhap Ten HS: ";
	cin.getline(HS.Ten, 50);
	cout << "Nhap diem Toan: ";
	cin >> HS.toan;
	cout << "Nhap diem Ly: ";
	cin >> HS.ly;
	cout << "Nhap diem Hoa: ";
	cin >> HS.hoa;
}
void XuatHS(HocSinh& HS) {
	cout << "ID HS: " << HS.ID << endl;
	cout << "Ten HS: " << HS.Ten << endl;
	cout << "Diem toan: " << HS.toan << endl;
	cout << "Diem ly: " << HS.ly << endl;
	cout << "Diem hoa: " << HS.hoa << endl;
	cout << "DTB: " << HS.dtb << endl;
}
// Câu 2: Tạo và nhập xuất danh sách học sinh.
void NhapDSHS(HocSinh HS[]) {
	cout << "Nhap so luong HS: ";
	cin >> soluong;
	for (int i = 0; i < soluong; i++) {
		cout << "Nhap HS thu " << i + 1 << endl;
		NhapHS(HS[i]);
	}
}
void XuatDSHS(HocSinh HS[]) {
	cout << "\n\n===> DSHS <===\n\n";
	for (int i = 0; i < soluong; i++) {
		XuatHS(HS[i]);
		cout << "--------------\n";
	}
}
// Câu 3: Sắp xếp học sinh theo điểm toán
void Swap(HocSinh& a, HocSinh& b) {
	HocSinh temp = a;
	a = b;
	b = temp;
}
void SapXepDiemToan(HocSinh HS[]) {
	for (int i = 0; i < soluong; i++) {
		for (int j = i + 1; j < soluong; j++) {
			if (HS[i].toan < HS[j].toan) {
				Swap(HS[i], HS[j]);
			}
		}
	}
}
// Câu 4: Tính điểm trung bình của lớp
float DTB(HocSinh& HS) {
	HS.dtb = (HS.toan + HS.ly + HS.hoa) / 3;
	return HS.dtb;
}
void DTBlop(HocSinh HS[]) {
	for (int i = 0; i < soluong; i++) {
		DTB(HS[i]);
	}
}
// Câu 5: Xuất ra học giỏi của lớp
void HSGlop(HocSinh HS[]) {
	int count = 0;
	cout << "===> HSG cua lop <===\n";
	for (int i = 0; i < soluong; i++) {
		if (HS[i].dtb > 8.5) {
			cout << HS[i].Ten << " == " << HS[i].dtb << endl;
			count++;
		}
	}
	if (count == 0) {
		cout << "  Lop khong co HSG !";
	}
}
// Câu 6: Đếm và xuất ra số lượng học sinh của từng loại. (Giỏi - Khá - TB - Yếu)
void DemVaXuatHL(HocSinh HS[]) {
	int HSG = 0, HSK = 0, HSTB = 0, HSY = 0;
	for (int i = 0; i < soluong; i++) {
		if (HS[i].dtb > 8.5) {
			HSG++;
		}
		if (HS[i].dtb > 7.0 && 8.5 > HS[i].dtb) {
			HSK++;
		}
		if (HS[i].dtb > 5.5 && 7.0 > HS[i].dtb) {
			HSTB++;
		}
		if (HS[i].dtb < 5.5)
		{
			HSY++;
		}
	}
	cout << "===> Hoc luc cua lop <===\n" << "HSG: " << HSG << "\nHSK: " << HSK << "\nHSTB: " << HSTB << "\nHSY: " << HSY;
}
//===============================================================================================
// Chuỗi
// Câu 9 :Nhập và xuất chuỗi (string).
void NhapChuoi(char A[]) {
	cout << "Nhap chuoi:";
	cin.getline(A, 50);
}
void XuatChuoi(char A[]) {
	cout << "Chuoi xuat:" << A;
}
// Câu 10: Tìm vị trí đầu tiên kí tự ‘a’ trong chuỗi.
void TimADau(char A[]) {
	for (int i = 0; i < strlen(A); i++) {
		if (A[i] == 'a') {
			cout << "Ky tu 'a' nam o vi tri: " << i;
			break;
		}
	}
}
// Câu 11: Tìm vị trí cuối cùng kí tự ‘a’ trong chuỗi.
void TimACuoi(char A[]) {
	for (int i = strlen(A) - 1; i >= 0; i--) {
		if (A[i] == 'a') {
			cout << "Ky tu 'a' nam o vi tri: " << i;
			break;
		}
	}
}
// Câu 12: Thay thế kí tự đầu tiên ‘a’ trong chuỗi bằng b
void ThayKiTu(char A[], int Vitri, char Kitu) {
	int n = strlen(A);
	for (int i = Vitri; i < strlen(A); i++) {
		A[Vitri] = Kitu;
	}
}
void ThayTheADauTien(char A[]) {
	for (int i = 0; i < strlen(A); i++) {
		if (A[i] == 'a') {
			ThayKiTu(A, i, 'b');
			break;
		}
	}
}
// Câu 13: Thay thế tất cả kí tự ‘a’ trong chuỗi bằng b
void ThayTheTatCaA(char A[]) {
	for (int i = 0; i < strlen(A); i++) {
		if (A[i] == 'a') {
			ThayKiTu(A, i, 'b');
		}
	}
}
// Câu 14: Xác định chuỗi có phải chỉ chứa số không ? chỉ chứa 0,1,2,3,4,5,6,7,8,9
void XacDinhChuoiChuaSo(char A[]) {
	int count = 0;
	for (int i = 0; i < strlen(A); i++) {
		if (A[i] >= 48 && A[i] <= 57) {
			count++;
			continue;
		}
		else
		{
			cout << "Chuoi chua ky tu khac so !";
			break;
		}
	}
	if (count == strlen(A)) {
		cout << "Chuoi chi chua so !";
	}
}
// Câu 15: Xác định chuỗi có phải chỉ chứa kí tự a-z A->Z
void XacDinhChuoiChuaKT(char A[]) {
	int count = 0;
	for (int i = 0; i < strlen(A); i++) {
		if (A[i] >= 65 && A[i] <= 90 || A[i] >= 97 && A[i] <= 122) {
			count++;
			continue;
		}
		else
		{
			cout << "Chuoi chua ky tu khac !";
			break;
		}
	}
	if (count == strlen(A)) {
		cout << "Chuoi chi chua ky tu !";
	}
}
// Câu 16: Chuyển tất các các chữ cái đầu của từng từ  thành in hoa.
void FormatChuCaiDau(char A[]) {
	for (int i = 0; i < strlen(A); i++) {
		if (A[0] >= 'a' && A[0] <= 'z'){
			A[0] -= 32;
		}
		if (A[i] == ' ' && (A[i + 1] >= 'a' && A[i + 1] <= 'z')) {
			A[i + 1] -= 32;
		}
	}
}
// Câu 17: Chuẩn hóa chuỗi. Xóa các khoảng trắng bị lặp lại trong chuỗi và xóa tất cả khoảng trắng đầu và cuối chuỗi.
void Xoa(char A[], int Vitri) {
	int n = strlen(A);
	for (int i = Vitri; i < strlen(A); i++) {
		A[i] = A[i + 1];
	}
	n--;
}
void XoaKhoangTrang(char A[]) {
	while (A[0] == ' ' || strlen(A) - 1 == ' ')
	{
		if (A[0] == ' ') { Xoa(A, 0); }
	}
	for (int i = 0; i < strlen(A) - 1; i++) {
		while (A[i] == ' ' && A[i + 1] == ' ')
		{
			Xoa(A, i + 1);
		}
		while (i == strlen(A) - 1 && A[i] == ' ')
		{
			Xoa(A, i);
		}
	}
}
// Câu 18: Chèn 1 kí tự vào vị trí đầu tiên, cuối cùng, bất kì của chuỗi.
void Chen(char A[], int Vitri, char Kitu) {
	int n = strlen(A);
	for (int i = n - 1; i >= Vitri; i--) {
		A[i + 1] = A[i];
	}
	A[Vitri] = Kitu;
	A[n + 1] = '\0';
}
void ChenNhap(char A[], int &VT, char &KT) {
	int n = strlen(A);
	for (int i = n - 1; i >= VT; i--) {
		A[i + 1] = A[i];
	}
	A[VT] = KT;
	A[n + 1] = '\0';
}
void ChenKiTuDauTien(char A[]) {
	Chen(A, 0, 'H');
}
void ChenKiTuCuoi(char A[]) {
	Chen(A, strlen(A), 'y');
}
void ChenBatKi(char A[]) {
	int Vitri;
	char Kitu;
	cout << "Nhap vi tri can chen: ";
	cin >> Vitri;
	cout << "Nhap ki tu can chen: ";
	cin >> Kitu;
	ChenNhap(A, Vitri,Kitu);
	
}
// Câu 19: Chèn 1 chuỗi vào vị trí đầu tiên, cuối cùng, bất kì của chuỗi.
void Copy(const char Nguon[],char Diemdem[], const int Batdau, const int Ketthuc) {
	for (int i = Batdau, j = 0; i < Ketthuc; i++,j++) {
		Diemdem[j] = Nguon[i];
		Diemdem[Ketthuc - Batdau] = '\0';
	}
}
void ChenChuoiVaoViTriX(char A[], int &VT) {
	char temp1[100], temp2[100];
	char Ketqua[100] = "";
	char B[100];
	cout << "Nhap vi tri chen chuoi: ";
	cin >> VT;
	cin.ignore();
	cout << "Nhap chuoi chen: ";
	cin.getline(B, 50);
	if (VT == 0) {
		strcat(Ketqua, B);
		strcat(Ketqua, A);
	}
	if (VT == strlen(A) - 1) {
		strcat(Ketqua, A);
		strcat(Ketqua, B);
	}
	if (VT > 0 && VT < strlen(A) - 1) {
		Copy(A, temp1, 0, VT);
		Copy(A, temp2, VT, strlen(A));
		strcat(Ketqua, temp1);
		strcat(Ketqua, B);
		strcat(Ketqua, temp2);
	}
	cout << "Chuoi sau khi chen: " << Ketqua;

}
// Câu 20: So sánh 2 chuỗi có giống nhau không
void SoSanh(char A[]) {
	char B[100];
	cout << "Nhap chuoi B:";
	cin.getline(B, 50);
	int sosanh = strcmp(A, B);
	if (sosanh == 1) {
		cout << "Chuoi A lon hon B !";
	}
	if (sosanh == -1){
		cout << "Chuoi B lon hon A !";
	}
	if (sosanh == 0) {
		cout << "2 chuoi bang nhau !";
	}
}
// Câu 21: Chuyển tất các các kí tự thường thành in hoa.
void UpperCase(char A[]) {
	for (int i = 0; i < strlen(A); i++) {
		if (A[i] >= 65 && 90 >= A[i] || A[i] == 32) {
			continue;
		}
		else
		{
			A[i] -= 32;
		}
	}
}
// Câu 22: Chuyển tất các các kí tự in hoa thành thường.
void LowerCase(char A[]) {
	for (int i = 0; i < strlen(A); i++) {
		if (A[i] >= 97 && 122 >= A[i] || A[i] == 32) {
			continue;
		}
		else
		{
			A[i] += 32;
		}
	}
}
// Câu 23: Nhập 1 số nguyên và chuyển về dạng string.
void ChuyenDoiChar(char A[], int& songuyen) {
	cout << "Nhap n: ";
	cin >> songuyen;
	int k = 0;
	int m = 1;
	for (int i = 0; m <= songuyen; i++) {
		A[k] = (songuyen / m) % 10 + 48;
		m *= 10;
		k++;
	}
	cout << "Chuoi sau khi chuyen !" << endl;
	for (int i = k - 1; i >= 0; i--) {
		cout << A[i];
	}
}
// Câu 24: Format lại string số trên : VD: 123456 = > 123, 456
void FormatChuoiSo(char A[]) {
	for (int i = strlen(A) - 3; i > 0; i -= 3) {
		Chen(A, i, ',');
	}
}
// Câu 25: Nhập số thập phân tối đa 2 chữ số thập phân và format chuỗi đó : VD: 123456.123 = > 123, 456.12 , VD: 123456.1 = > 123, 456.10
void FormatThapPhan(char A[]) {
	for (int i = strlen(A) - 6; i > 0; i -= 3) {
		while (A[strlen(A) - 3] != '.')
		{
			cout << "Nhap sai cu phap , moi nhap lai chu so thap phan chi co 2 so: ";
			cin.getline(A, 50);
		}
		Chen(A, i, ',');
	}
}
// Câu 27: Tác chuỗi  trên thành những chuỗi con theo kí tự “-” : VD: “abc - bcd - efg” = > [“abc”, “bcd”, “efg”]
void CheckChuoiCon(char A[]) {
	for (int i = 0; i < strlen(A); i++) {
		while (A[0] != '"' && A[strlen(A) - 1] != '"'){
			cout << "Sai cu phap , nhap lai: ";
			cin.getline(A, 50);
		}
		while (A[i] == '-' && A[i - 1] != ' ' && A[i + 1] != ' ')
		{
			cout << "Sai cu phap , nhap lai: ";
			cin.getline(A, 50);
		}
	}
}
void FormatChuoiCon(char A[]) {
	Chen(A, 0, '[');
	Chen(A, strlen(A), ']');
	for (int i = 0; i < strlen(A); i++) {
		if (A[i] == ' ') {
			A[i] = '"';
		}
		if (A[i] == '-') {
			A[i] = ',';
		}
	}
}
// Câu 28: Cộng, trừ 2 chuỗi số nguyên.
void Nhap2Chuoi(char A[], char B[]) {
	cout << "Nhap chuoi A: ";
	cin.getline(A, 50);
	cout << "Nhap chuoi B: ";
	cin.getline(B, 50);
}
void Them0(char A[], char B[]) {
	int max = 0;
	int n1 = strlen(A);
	int n2 = strlen(B);
	if (n1 > n2) {
		max = strlen(A) - strlen(B);
	}
	else if (n1 < n2){
		max = strlen(B) - strlen(A);
	}
	for (int i = 0; i < max; i++) {
		if (n1 < n2) {
			Chen(A, 0, '0');
		}
		else if (n2 < n1) {
			Chen(B, 0, '0');
		}
	}
}
void TinhTong(char A[], char B[], char KETQUA[]) {
	
	int nho = 0, k = 0, kq = 0;
	for (int i = strlen(A) - 1; i >= 0; i--) {
		kq = (A[i] - 48) + (B[i] - 48) + nho;
		nho = kq / 10;
		KETQUA[k] = (kq % 10) + 48;
		k++;
	}
	strrev(KETQUA);
}
void TinhHieu(char A[], char B[], char KETQUA[]) {
	int k = 0; int nho = 0;
	for (int i = strlen(A) - 1; i >= 0; i--) {
		int kq = (A[i] - '0') - (B[i] - '0') - nho;
		if (kq < 0) {
			KETQUA[k] = (kq + 10) + 48;
			nho = 1;
			k++;
		}
		else {
			KETQUA[k] = kq + 48;
			nho = 0;
			k++;
		}
	}
	strrev(KETQUA);
}
void TinhHieuCheck(char A[], char B[], char KETQUA[]) {
	bool ok = false;
	int x;
	if (A[0] == '-' && B[0] == '-' || A[0] != '-' && B[0] != '-') {
		if (A[0] == '-' && B[0] == '-') {
			Xoa(A, 0);
			Xoa(B, 0);
			x = strcmp(A, B);
			if (x == -1) {
				swap(A, B);
			}
			if (x == 1) {
				ok = true;
			}
		}
		else if (A[0] != '-' && B[0] != '-') {
			x = strcmp(A, B);
			if (x == -1) {
				ok = true;
				swap(A, B);
			}
		}
		Them0(A, B);
		TinhHieu(A, B, KETQUA);
	}
	else if (A[0] != '-' && B[0] == '-' || A[0] == '-' && B[0] != '-') {
		if (A[0] != '-' && B[0] == '-') {
			Xoa(B, 0);
		}
		else if (A[0] == '-' && B[0] != '-') {
			Xoa(A, 0);
			ok = true;
		}
		Them0(A, B);
		TinhTong(A, B, KETQUA);
	}
	//============================
	if (KETQUA[0] == '0') {
		Xoa(KETQUA, 0);
	}
	if (ok == true) {
		Chen(KETQUA, 0, '-');
	}
	cout << KETQUA;
}
//===============================================================================================
// Mảng
// Câu 29: Nhập xuất mảng với N phần tử, n < 100;
void NhapMang(int Arr[], int& n) {
	cout << "Nhap so luong phan tu: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Nhap gia tri tai vi tri thu " << i << ": " ;
		cin >> Arr[i];
	}
}
void XuatMang(int Arr[], int& n) {
	for (int i = 0; i < n; i++) {
		cout << "Gia tri tai vi tri thu " << i << " la: " << Arr[i] << endl;
	}
}
// Câu 30: Xuất giá trị tại phần tử thứ x: VD: mang array có giá trị là : 10 20 40 50 80, khi nhập x = 2 => xuất ra array[2] có giá trị là: 40
void XuatGiaTriX(int Arr[], int& n) {
	int x;
	cout << "Nhap vi tri muon xuat phan tu: ";
	cin >> x;
	cout << "Gia tri xuat tai vi tri " << x << " la: " << Arr[x];
}
// Câu 31: Thay thế giá trị tại vị trí x của phần tử = giá trị mới và xuất ra màn hình
void ThayGiaTriX(int Arr[], int& n) {
	int x, y;
	cout << "Nhap vi tri muon thay doi phan tu: ";
	cin >> x;
	cout << "Nhap gia tri thay doi: ";
	cin >> y;
	Arr[x] = y;
}
// Câu 32: Thay thế tất cả giá trị x = y
void ThayTayCaXBangY(int Arr[], int& n) {
	int x, y;
	cout << "Nhap vi tri muon thay doi phan tu: ";
	cin >> x;
	cout << "Nhap gia tri thay doi: ";
	cin >> y;
	for (int i = 0; i < n; i++) {
		if (Arr[i] == x) {
			Arr[i] = y;
		}
	}
}
// Câu 33: Tính tổng các phần tử
void TinhTongMang(int Arr[], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += Arr[i];
	}
	cout << "Tong cac phan tu: " << sum;
}
// Câu 34: Tính tổng các phần tử lẻ
void TinhTongLe(int Arr[], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (Arr[i] % 2 != 0) {
			sum += Arr[i];
		}
	}
}
// Câu 35: Tinh giá trị trung bình
float TinhTrungBinh(int Arr[], int& n) {
	int tb = 0;
	for (int i = 0; i < n; i++) {
		tb += Arr[i];
	}
	tb /= n;
	return tb;
	cout << "Gia tri trung binh cua mang: " << tb;
}
// Câu 36: Tính tổng giai thừa
void TinhGiaiThua(int Arr[], int& n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int temp = 1;
		for (int j = 1; j <= Arr[i]; j++) {
			temp *= j;
		}
		sum += temp;
	}
	cout << "Tong giai thua mang: " << sum;
}
// Câu 37: Tìm vị trí của phần tử
void TimViTri(int Arr[], int& n) {
	int x;
	cout << "Nhap gia tri muon tim: ";
	cin >> x;
	for (int i = 0; i < n; i++) {
		if (x == Arr[i]) {
			cout << "Gia tri " << Arr[i] << " nam o vi tri thu " << i;
		}
	}
}
// Câu 38: Tìm giá trị lớn nhất , nhỏ nhất
void TimMinMax(int Arr[], int& n) {
	int min = Arr[0], max = Arr[0];
	for (int i = 1; i < n; i++) {
		if (min > Arr[i]) {
			min = Arr[i];
		}
		if (max < Arr[i]) {
			max = Arr[i];
		}
	}
	cout << "Gia tri lon nhat cua mang: " << max << endl;
	cout << "Gia tri nho nhat cua mang: " << min;
}
// Câu 39: Sắp xếp mảng tăng , giảm dần
void SwapInt(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
void SapXepTang(int Arr[], int& n) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (Arr[i] < Arr[j]) {
				SwapInt(Arr[i], Arr[j]);
			}
		}
	}
}
void SapXepGiam(int Arr[], int& n) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (Arr[i] > Arr[j]) {
				SwapInt(Arr[i], Arr[j]);
			}
		}
	}
}
// Câu 40: Tìm và xuất ra màn hình các số NT
bool CheckSNT(int n) {
	if (n < 2) {
		return false;
	}
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}
void XuatSNT(int Arr[],int& n) {
	cout << "Cac so nguyen to trong mang: " << endl;
	for (int i = 0; i < n; i++) {
		if (CheckSNT(Arr[i])) {
			cout << Arr[i] << " ";
		}
	}
}
// Câu 41: Copy mảng và đảo chiều
void CopyMang(int Arr[], int& n) {
	int Brr[100];
	for (int i = 0; i < n; i++) {
		Brr[i] = Arr[i];
	}
	cout << "Mang ban dau: " << endl;
	XuatMang(Arr, n);
	cout << "Mang sau khi dao nguoc: " << endl;
	for (int i = n - 1, j = 0; i >= 0 , j < n; i--, j++) {
		cout << "Gia tri tai vi tri thu " << j << " la: " << Brr[i] << endl;
	}
}
// Câu 42: Thêm 1 giá trị vào mảng 
void Them(int a[],int &n,int viTri, int giaTri) {
	for (int i = n ; i >= viTri ; i--) {
		a[i] = a[i - 1];
	}
	a[viTri] = giaTri;
	n++;
}
void ThemPhanTu(int Arr[], int& n) {
	int viTri, giaTri;
	cout << "Nhap vi tri chen: ";
	cin >> viTri;
	cout << "Nhap gia tri chen: ";
	cin >> giaTri;
	for (int i = viTri; ; ) {
		Them(Arr, n, viTri, giaTri);
		break;
	}
	XuatMang(Arr, n);
}
// Câu 44: Không cần nhập giá trị N (length - độ dài của mảng), cho người dùng nhập cho tới khi nào nhập 0 thì dừng lại và xuất ra mảng đó, độ dài tối đa là 100 phần tử, nếu nhập tới 100 phần tử thì báo đã tới giới hạn và xuất ra tất cả giá trị của mảng người dùng đã nhập. (*)
void NhapMangVoHan(int Arr[]) {
	int count = 0;
	for (int i = 0; ; i++) {
		cout << "Nhap gia tri tai vi tri thu " << i << " la: ";
		cin >> Arr[i];
		count++;
		if (Arr[i] == 0 || count == 99) {
			break;
		}
	}
	for (int i = 0; i < count - 1; i++) {
		cout << "Gia tri tai vi tri thu " << i << " la: " << Arr[i] << endl;
	}
}
// Câu 45: Tìm giá trị gần với giá trị trung bình của toàn mảng
bool chuaXH(int arr[], int n, int v) {
	for (int i = 0; i < n; i++) {
		if (arr[i] == v) {
			return false;
		}
	}
	return true;
}
void GiaTriGanVoiTrungBinhMang(int Arr[], int& n) {
	int Brr[100]; int count = 0;
	int x = TinhTrungBinh(Arr, n);
	int min = abs(Arr[0] - x);
	for (int i = 1; i < n; i++) {
		if (abs(Arr[i] - x) < min) {
			min = abs(Arr[i] - x);
		}
	}
	for (int i = 0; i < n; i++) {
		if (abs(Arr[i] - x) == min && chuaXH(Brr,count,Arr[i])) {
			cout << "Gia tri gan voi trung binh: " << Arr[i] << endl;
			Brr[count++] = Arr[i];
		}
	}
}
// Câu 46: Nhập giá trị cho 2 mảng bất kì. Tìm tất cả các số nằm trong mảng này nhưng không nằm trong mảng kia. 
// VD: arr1 = { 1,2,3,5,7,9 } arr2 = { 2,3,7,8,9 } = > xuất ra màn hình 1, 5, 8
void nhap2Mang(int Arr[], int Brr[], int& n, int& m) {
	cout << "Nhap so luong phan tu mang A: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Nhap gia tri tai vi tri thu " << i << " la: ";
		cin >> Arr[i];
	}
	cout << "Nhap so luong phan tu mang B: ";
	cin >> m;
	for (int i = 0; i < m; i++) {
		cout << "Nhap gia tri tai vi tri thu " << i << " la: ";
		cin >> Brr[i];
	}
}
void timGiaTri(int Arr[], int Brr[], int& n, int& m) {
	int Crr[100] = { 0 };
	int count[100] = { 0 };
	for (int i = 0, j = n; i < n; i++, j++) {
		Crr[i] = Arr[i];
		Crr[j] = Brr[i];
	}
	for (int i = 0; i < (n + m); i++) {
		count[Crr[i]]++;
	}
	cout << "Gia tri khong xuat hien cua 2 mang: ";
	for (int i = 0; i < (n + m); i++) {
		if (count[Crr[i]] == 1) {
			cout << Crr[i] << " ";
		}
	}
}
// Câu 47: Nhập giá trị cho 2 mảng bất kì có số lượng phần tử M N, tối đa 100 phần tử. So sánh xem 2 mảng đó có giống nhau không.
// VD: arr1 = { 1,2,3 } arr2 = { 3, 2, 1 } = > xuất ra màn hình 2 mảng này KHÔNG giống nhau
// VD : arr1 = { 1,2,3 } arr2 = { 1, 2, 3 } = > xuất ra màn hình 2 mảng này giống nhau
void nhap2MangSoSanh(int Arr[], int Brr[], int& n) {
	cout << "Nhap so luong phan tu 2 mang: ";
	cin >> n;
	cout << "Nhap mang A: " << endl;
	for (int i = 0; i < n; i++) {
		cout << "Nhap gia tri tai vi tri thu " << i << " la: ";
		cin >> Arr[i];
	}
	cout << "Nhap mang B: " << endl;
	for (int i = 0; i < n; i++) {
		cout << "Nhap gia tri tai vi tri thu " << i << " la: ";
		cin >> Brr[i];
	}
}
void soSanh2Mang(int Arr[], int Brr[], int& n) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (Arr[i] == Brr[i]) {
			count++;
			continue;
		}
		else
		{
			cout << "2 mang KHONG GIONG nhau !";
			break;
		}
	}
	if (count == n) {
		cout << "2 mang GIONG nhau !";
	}
}
// Câu 48: Nhập giá trị cho 2 mảng bất kì có số lượng phần tử M N, tối đa 100 phần tử. So sánh xem 2 mảng đó có giá trị giống nhau không.
// VD: arr1 = { 1,2,3 } arr2 = { 3, 2, 1 } = > xuất ra màn hình 2 mảng này có giá trị giống nhau
void nhap2MangSoSanhGiaTri(int Arr[], int Brr[], int& n) {
	cout << "Nhap so luong phan tu 2 mang: ";
	cin >> n;
	cout << "Nhap mang A: " << endl;
	for (int i = 0; i < n; i++) {
		cout << "Nhap gia tri tai vi tri thu " << i << " la: ";
		cin >> Arr[i];
	}
	cout << "Nhap mang B: " << endl;
	for (int i = 0; i < n; i++) {
		cout << "Nhap gia tri tai vi tri thu " << i << " la: ";
		cin >> Brr[i];
	}
}
void soSanhGiaTri(int Arr[], int Brr[], int& n) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (Arr[i] == Brr[j]) {
				count++;
			}
		}
	}
	if (count == n) {
		cout << "2 mang co gia tri GIONG nhau !";
	}
	else
	{
		cout << "2 mang co gia tri KHONG GIONG nhau !";
	}

}
// Câu 50: Nhập mảng và đọc các phần tử của mảng
//VD: arr = { 1,2,30, 4 } = > Mot - Hai - Ba Khong - Bon
void docMang(int Arr[], int& n) {
	for (int i = 0; i < n; i++) {
		int a = Arr[i] % 10;
		int b = (Arr[i] / 10) % 10;
		int c = (Arr[i] / 100) % 10;
		switch (c)
		{
		case 1: cout << "Mot Tram "; break;
		case 2: cout << "Hai Tram "; break;
		case 3: cout << "Ba Tram "; break;
		case 4: cout << "Bon Tram "; break;
		case 5: cout << "Nam Tram "; break;
		case 6: cout << "Sau Tram "; break;
		case 7: cout << "Bay Tram "; break;
		case 8: cout << "Tam Tram "; break;
		case 9: cout << "Chin Tram "; break;
		}
		switch (b)
		{
		case 1: cout << "Muoi "; break; 
		case 2: cout << "Hai Muoi " ; break;
		case 3: cout << "Ba Muoi " ; break;
		case 4: cout << "Bon Muoi " ; break;
		case 5: cout << "Nam Muoi " ; break;
		case 6: cout << "Sau Muoi " ; break;
		case 7: cout << "Bay Muoi " ; break;
		case 8: cout << "Tam Muoi " ; break;
		case 9: cout << "Chin Muoi " ; break;
		}
		if (c > 0 && (b / 10) % 10 == 0) {
			cout << "Le ";
		}
		switch (a)
		{
		case 0: cout << "Khong" << endl; break;
		case 1: cout << "Mot" << endl; break;
		case 2: cout << "Hai" << endl; break;
		case 3: cout << "Ba" << endl; break;
		case 4: cout << "Bon" << endl; break;
		case 5: 
			if (b > 0) 
			{ cout << "Lam" << endl; break; }
			else 
			{ cout << "Nam" << endl; break; }
		case 6: cout << "Sau" << endl; break;
		case 7: cout << "Bay" << endl; break;
		case 8: cout << "Tam" << endl; break;
		case 9: cout << "Chin" << endl; break;
		}
	}
}
// Câu 51: Nhập mảng và xóa tất cả các phần tử trùng nhau
// VD: arr = { 1,2,30, 2 } = > arr = { 1,2,30 }
void xoaMang(int Arr[],int &n, int viTri) {
	for (int i = viTri; i < n; i++) {
		Arr[i] = Arr[i + 1];
	}
	n--;
}
void xoaPhanTuTrung(int Arr[], int& n) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j ++ ) {
			if (Arr[i] == Arr[j]) {
				xoaMang(Arr, n, j);
			}
		}
	}
}
//Câu 52: Tìm tất chuỗi tăng dần
//VD: arr = { 1,2,30, 4, 5, 0 } = > chuỗi tăng dần 1, 2, 30 và 4, 5
void timMangTang(int Arr[], int& n) {
	int count = 0;
	cout << "Mang tang dan la: " << endl;
	for (int i = 0; i < n; i++) {
		while (Arr[i] < Arr[i + 1])
		{
			if (count == 0) {
				cout << Arr[i] << " " << Arr[i + 1] << " ";
			}
			else
			{
				cout << Arr[i + 1] << endl;
			}
			i++, count++;
		}
		count = 0;
	}
}
//Câu 53: Tìm chuỗi tăng dần dài nhất 
void timMangTangDaiNhat(int Arr[], int& n) {
	int count[100];
	for (int i = 0; i < n; i++) {
		count[i] = 1;
	}
	for (int i = n - 1; i > 0; i--) {
		if (Arr[i] > Arr[i - 1]) {
			count[i - 1] += count[i];
		}
	}
	int max = count[0];
	for (int i = 0; i < n; i++) {
		if (max < count[i]) {
			max = count[i];
		}
	}
	for (int i = 0; i < n; i++) {
		if (count[i] == max) {
			cout << "Mang tang dai nhat: ";
			for (int j = i; j < (i + max); j++) {
				cout << Arr[j] << " ";
			}
			break;
		}
	}
}
//Câu 54: Tìm chuỗi tăng có tổng giá trị là nhỏ nhất, lớn nhất
void timMangTangMinMax(int Arr[] , int &n) {
	int tong[100];
	int vitri[100];
	for (int i = 0; i < n; i++) {
		tong[i] = Arr[i];
		vitri[i] = 1;
	}
	for (int i = n - 1; i > 0; i--) {
		if (Arr[i] > Arr[i - 1]) {
			tong[i - 1] += tong[i];
			tong[i] = 0;
			vitri[i - 1] += vitri[i];
		}
	}
	int min = tong[0], max = tong[0];
	for (int i = 0; i < n; i++) {
		if (max < tong[i]) {
			max = tong[i];
		}
		if (min > tong[i] && tong[i] != 0) {
			min = tong[i];
		}
	}
	for (int i = 0; i < n; i++) {
		if (tong[i] == max) {
			cout << "Mang tang co gia tri lon nhat: ";
			for (int j = i; j < (vitri[i] + i); j++) {
				cout << Arr[j] << " ";
			}
			break;
		}
	}
	cout << endl << "Gia tri cua mang: " << max;
	for (int i = 0; i < n; i++) {
		if (tong[i] == min) {
			cout << endl << "Mang tang co gia tri nho nhat: ";
			for (int j = i; j < (vitri[i] + i); j++) {
				cout << Arr[j] << " ";
			}
			break;
		}
	}
	cout << endl << "Gia tri cua mang: " << min;
}
//Câu 55: Xóa tất cả các chuỗi có tổng giá trị nhỏ hơn 20
//VD: arr = { 1,2,30, 4, 5, 0, 20 } = > arr = { 1, 2, 30, 0, 20 }
void xoaMangTongDuoi20(int Arr[], int& n) {
	int giatrixoa;
	int sum = 0;
	cout << "Nhap gia tri muon xoa: ";
	cin >> giatrixoa;
	if (Arr[0] > Arr[1]) {
		xoaMang(Arr, n, 0);
	}
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (Arr[j] < Arr[j + 1]) {
				sum += Arr[j];
			}
			else
			{
				sum += Arr[j];
				if (sum >= giatrixoa) {
					i = j;
				}
				if (sum < giatrixoa) { // 1 3 5 4 8 12 10 15 30
					for (int k = i; k <= j; k++) {
						xoaMang(Arr, n, i);
					}
					i--;
					sum = 0;
					break;
				}
			}
		}
	}
}
//Câu 56: Nhập vào 1 số tự nhiên, đổi số đó ra mảng
//VD: N = 123 = > arr = { 1,2,3 }
void chuyenDoiMang() {
	int arr[100];
	int k = 0;
	int m = 1;
	int stn, sl;
	cout << "Nhap so muon chuyen doi: ";
	cin >> stn;
	cout << "Nhap so luong tach: ";
	cin >> sl;
	switch (sl)
	{
	case 1:
		while (m < stn)
		{
			arr[k] = (stn / m) % 10;
			k++, m *= 10;
		}
	case 2:
		while (m < stn)
		{
			arr[k] = (stn / m) % 10;
			m *= 10;
			arr[k] += ((stn / m) % 10) * 10;
			k++; m *= 10;
		}
	case 3:
		while (m < stn)
		{
			arr[k] = (stn / m) % 10;
			m *= 10;
			arr[k] += ((stn / m) % 10) * 10;
			m *= 10;
			arr[k] += ((stn / m) % 10) * 100;
			k++;
			m *= 10;
		}
	}
	for (int i = k - 1; i >= 0; i--) {
		cout << arr[i] << " ";
	}
}
//Câu 58: Xuất ra số lần lặp của tất cả các số trong mảng và sắp xếp các lần lặp giảm dần
void demMang(int Arr[], int& n) {
	int count[100] = { 0 };
	for (int i = 0; i < n; i++) {
		count[Arr[i]]++;
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (count[Arr[i]] < count[Arr[j]]) {
				SwapInt(Arr[i], Arr[j]);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (count[Arr[i]] != 0) {
			cout << Arr[i] << " xuat hien " << count[Arr[i]] << " lan" << endl;
			count[Arr[i]] = 0;
		}
	}
}
//Câu 59: Sử dụng bài (Thay thế giá trị tại vị trí x của phần tử = giá trị mới và xuất ra màn hình) và sau khi xuất xong thì hiển thị bảng chọn có muốn thay thế các số trên bằng số khác không), khi đã thay thế hết thì xuất ra và lặp lại.
void bangChon(int Arr[], int& n) {
	ThayGiaTriX(Arr, n);
	XuatMang(Arr, n);
	int luachon;
	do
	{
		cout << "Ban co muon tiep tuc ?\n" << "1.Co\n" << "2.Khong\n";
		cin >> luachon;
		while (luachon < 1 || luachon > 2)
		{
			cout << "Nhap vuot gia tri cho phep, nhap lai: ";
			cin >> luachon;
		}
		switch (luachon)
		{
		case 1:
			ThayGiaTriX(Arr, n); 
			XuatMang(Arr, n);
			break;
		case 2: 
			XuatMang(Arr, n);
			break;
		}
	} while (luachon != 2);

}
// Hàm in bảng cửu chương !
void cuuChuong() {
	for (int i = 2; i < 10; i++) {
		cout << "=== BANG CUU CUONG " << i << " ===\n\n";
		for (int j = 1; j <= 10; j++) {
			int sum = 0;
			sum = i * j;
			cout << i << " * " << j << " = " << sum << endl;
		}
		cout << "\n\n";
	}
}
// Tính tiền taxi !
void tinhTienTaXi() {
	int tongtien = 0;
	int sokm;
	cout << "Nhap vao so km da di: ";
	cin >> sokm;
	if (sokm == 1) {
		tongtien += 15000;
	}
	if (sokm > 1 && sokm < 6) {
		tongtien += 13500 * (sokm - 1) + 15000;
	}
	if (sokm > 5) {
		tongtien += (11000 * (sokm - 5)) + (13500 * (5 - 1)) + 15000;
	}
	if (sokm > 120) {
		tongtien /= 0.9;
	}
	cout << "Tong tien phai tra cho km da di: " << tongtien;
}
// Bài tập trả tiền !
// Cách 1:
void traTien1() {
	int giatien[10] = { 500,200,100,50,20,10,5,2,1 };
	int count[501] = { 0 };
	int khachdua, giatrimonhang;
	int tienthoi = 0;
	cout << "Nhap so tien khach dua: ";
	cin >> khachdua;
	cout << "Gia tri mon hang: ";
	cin >> giatrimonhang;
	tienthoi = khachdua - giatrimonhang;
	for (int i = 0; i < 9; i++) {
		if (tienthoi >= giatien[i]) {
			count[giatien[i]] = tienthoi / giatien[i];
			tienthoi %= giatien[i];
		}
	}
	for (int i = 0; i < 10; i++) {
		if (count[giatien[i]] != 0) {
			cout << "Menh gia " << giatien[i] << " " << " - " << count[giatien[i]] << endl;
			count[giatien[i]] = 0;
		}
	}
}
// Cách 2:
void traTien2() {
	int giatien[10] = { 500,200,100,50,20,10,5,2,1 };
	int count[10] = { 0 };
	int khachdua, giatrimonhang;
	int tienthoi = 0;
	cout << "Nhap so tien khach dua: ";
	cin >> khachdua;
	cout << "Gia tri mon hang: ";
	cin >> giatrimonhang;
	tienthoi = khachdua - giatrimonhang;
	for (int i = 0; i < 9; i++) {
		int k = i;
		if (tienthoi >= giatien[i]) {
			count[k] = tienthoi / giatien[i];
			tienthoi %= giatien[i];
		}
	}
	for (int i = 0; i < 9; i++) {
		if (count[i] != 0) {
			cout << "Menh gia " << giatien[i] << " - " << count[i] << endl;
		}
	}
}
// Caro thủ công !
int docbanco,ngangbanco;
void veBanCo(char C[10][10]) {
	cout << "\t\t\t\t\t\t=== BAN CO CA RO ===\n\n";
	cout << "\t\t\t\t\t\t  ";

	for (int i = 0; i < docbanco; i++) {
		cout << i << " ";
	}
	for (int i = 0; i < ngangbanco; i++) {
		cout << "\n\t\t\t\t\t\t" << i << " ";
		for (int j = 0; j < docbanco; j++) {
			cout << C[i][j];
			cout << " ";
		}
	}
}
void taoBanCo(char C[10][10]) {
	cout << "Nhap kich thuoc ban co !\n";
	cout << "Kich thuoc doc: ";
	cin >> docbanco; 
	cout << "Kich thuoc ngang: ";
	cin >> ngangbanco;
	cout << "\t\t\t\t\t\t===  BAN CO CA RO  ===\n\n";
	cout << "\t\t\t\t\t\t  ";
	for (int i = 0; i < docbanco; i++) {
		cout << i << " ";
	}
	for (int i = 0; i < ngangbanco; i++) {
		cout << "\n\t\t\t\t\t\t" << i << " ";
		for (int j = 0; j < docbanco; j++) {
			C[i][j] = '-';
			cout << C[i][j] << " ";
		}
	}
}
void danhCo(char C[10][10]) {
	taoBanCo(C);
	char x = 'X';
	int hangngang, hangdoc;
	int tieptuc = 1;
	int win = 0;
	do
	{
		int count = 0;
		if (x == 'X') {
			cout << "\n\tLuot nguoi choi X !\n";
			cout << "\tX nhap hang doc: ";
			cin >> hangdoc;
			cout << "\tX nhap hang ngang: ";
			cin >> hangngang;
		}
		else
		{
			cout << "\n\t\t\t\t\t\t\t\t\t\t\t\tLuot nguoi choi O !\n";
			cout << "\t\t\t\t\t\t\t\t\t\t\t\tO nhap hang doc: ";
			cin >> hangdoc;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\tO nhap hang ngang: ";
			cin >> hangngang;
		}
		
		while (hangngang >= ngangbanco || hangdoc >= docbanco) {
			cout << "Qua kich thuoc ban co, nhap lai !\n";
			cout << "Nhap hang doc: ";
			cin >> hangdoc;
			cout << "Nhap hang ngang: ";
			cin >> hangngang;
		}
		while (count == 0)
		{
			for (int i = hangngang; i <= ngangbanco; i++) {
				for (int j = hangdoc; j <= docbanco; j++) {
					if (i == hangngang && j == hangdoc && C[i][j] == '-') {
						C[i][j] = x;
						count++;
					}
					else
					{
						while (count == 0)
						{
							cout << "Vi tri ban co da duoc danh dau , nhap lai vi tri khac !\n";
							cout << "Nhap hang doc: ";
							cin >> hangdoc;
							cout << "Nhap hang ngang: ";
							cin >> hangngang;
							while (hangngang >= ngangbanco || hangdoc >= docbanco) {
								cout << "Qua kich thuoc ban co, nhap lai !\n";
								cout << "Nhap hang doc: ";
								cin >> hangdoc;
								cout << "Nhap hang ngang: ";
								cin >> hangngang;
							}
							for (int i = hangngang; i <= ngangbanco; i++) {
								for (int j = hangdoc; j <= docbanco; j++) {
									if (i == hangngang && j == hangdoc && C[i][j] == '-') {
										C[i][j] = x;
										count++;
									}
								}
							}
						}
					}
					break;
				}
				if (count != 0) {
					break;
				}
			}
			veBanCo(C);
			if (x == 'X') {
				x = 'O';
			}
			else
			{
				x = 'X';
			}
		}
		// Check cờ hàng ngang !
		for (int i = 0; i < ngangbanco; i++) {
			for (int j = 2; j < docbanco - 2; j++) {
				if (C[i][j] == 'X' && C[i][j - 1] == 'X' && C[i][j - 2] == 'X' && C[i][j + 1] == 'X' && C[i][j + 2] == 'X') {
					win = 1;
					break;
				}
				if (C[i][j] == 'O' && C[i][j - 1] == 'O' && C[i][j - 2] == 'O' && C[i][j + 1] == 'O' && C[i][j + 2] == 'O') {
					win = 2;
					break;
				}
			}
			if (win != 0) {
				break;
			}
		}
		// Check cò hàng dọc !
		for (int i = 2; i < ngangbanco - 2; i++) {
			for (int j = 0; j < docbanco; j++) {
				if (C[i][j] == 'X' && C[i - 1][j] == 'X' && C[i - 2][j] == 'X' && C[i + 1][j] == 'X' && C[i + 2][j] == 'X') {
					win = 1;
					break;
				}
				if (C[i][j] == 'O' && C[i - 1][j] == 'O' && C[i - 2][j] == 'O' && C[i + 1][j] == 'O' && C[i + 2][j] == 'O') {
					win = 2;
					break;
				}
			}
			if (win != 0) {
				break;
			}
		}
		for (int i = 2; i < ngangbanco - 2; i++) {
			for (int j = 2; j < ngangbanco - 2; j++) {
				if (C[i][j] == 'X' && C[i - 1][j - 1] == 'X' && C[i - 2][j - 2] == 'X' && C[i + 1][j + 1] == 'X' && C[i + 2][j + 2] == 'X'
					|| C[i][j] == 'X' && C[i + 1][j - 1] == 'X' && C[i + 2][j - 2] == 'X' && C[i - 1][j + 1] == 'X' && C[i - 2][j + 2] == 'X') {
					win = 1;
					break;
				}
				if (C[i][j] == 'O' && C[i - 1][j - 1] == 'O' && C[i - 2][j - 2] == 'O' && C[i + 1][j + 1] == 'O' && C[i + 2][j + 2] == 'O'
					|| C[i][j] == 'O' && C[i + 1][j - 1] == 'O' && C[i + 2][j - 2] == 'O' && C[i - 1][j + 1] == 'O' && C[i - 2][j + 2] == 'O') {
					win = 2;
					break;
				}
			}
			if (win != 0) {
				break;
			}
		}
		int checkbanco = 0;
		for (int i = 0; i < ngangbanco; i++) {
			for (int j = 0; j < docbanco; j++) {
				if (C[i][j] == 'X' || C[i][j] == 'O') {
					checkbanco++;
					continue;
				}
				else if (C[i][j] == '-') 
				{
					checkbanco = 0;
					break;
				}
			}
			if (checkbanco == 0) {
				break;
			}
		}
		if (checkbanco == ngangbanco * docbanco) {
			win = 3;
		}
		if (win != 0) {
			if (win == 1) {
				cout << "\n\n\t\t\t\t\t\tNguoi choi X thang !";
			}
			else if (win == 2)
			{
				cout << "\n\n\t\t\t\t\t\tNguoi choi O thang !";
			}
			else if (win == 3)
			{
				cout << "\n\n\t\t\t\t\t\tFULL kich thuoc ban co , HOA !";
			}
			/*cout << "\n\n\t\t\t\t\t\tBAN CO MUON TIEP TUC ?\n";
			cout << "\t\t\t\t\t\t1. Co !\n" << "\t\t\t\t\t\t2. Khong !\n";
			cout << "\t\t\t\t\t\t";
			cin >> tieptuc;*/
		}
	}while (win == 0);
}
int main() {
	HocSinh HS[100];
	char A[100], B[100];
	int Arr[100], Brr[100];
	char C[10][10];
	int n, m;
	char KETQUA[100] = "";
	int VT; int songuyen;
}