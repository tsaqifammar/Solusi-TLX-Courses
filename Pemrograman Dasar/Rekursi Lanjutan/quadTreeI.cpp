#include <iostream>
#include <string>

using namespace std;

int m[128][128];
int nJawaban;
string jawaban[128*128];

// Cek apakah submatrix [r, c, r+k-1, c+k-1] sudah homogen
bool homogen(int r, int c, int k) {
   int val = m[r][c];
   for (int i = r; i < r+k; i++) {
      for (int j = c; j < c+k; j++) {
         if (m[i][j] != val) {
            return false;
         }
      }
   }
   return true;
}

// Kodekan submatrix [r, c, r+k-1, c+k-1]
void quadtree(int r, int c, int k, string s){
   if (homogen(r,c,k)) {
      if (m[r][c] == 1) {
         jawaban[nJawaban] = "1" + s;
         nJawaban++;
      }
   } else {
      // Belah
      quadtree(r, c, k/2, s+"0");
      quadtree(r, c+(k/2), k/2, s+"1");
      quadtree(r+(k/2), c, k/2, s+"2");
      quadtree(r+(k/2), c+(k/2), k/2, s+"3");
   }
}

int main(){
   int r, c;
   scanf("%d %d", &r, &c);

   // Cari 2^p yang >= max(r, c)
   int maxRc = max(r, c);
   int pow2 = 1;
   while (pow2 < maxRc){
      pow2 *= 2;
   }

   // Inisialisasi
   for (int i = 0; i < pow2; i++) {
      for (int j = 0; j < pow2; j++) {
         m[i][j] = 0;
      }
   }

   // Baca masukan
   for (int i = 0; i < r; i++){
      for (int j = 0; j < c; j++){
         scanf("%d", &m[i][j]);
      }
   }

   // Kodekan
   nJawaban = 0;
   quadtree(0, 0, pow2, "");

   // Cetak
   printf("%d\n", nJawaban);
   for (int i = 0; i < nJawaban; i++) {
      printf("%s\n", jawaban[i].c_str());
   }

   return 0;
}
