# AEON — GitHub Pages + WebAssembly (v0.2.0)

Versi tanpa server backend. Antarmuka statis di-host oleh GitHub Pages; solver numerik ditulis dalam C++ dan dikompilasi ke WebAssembly oleh GitHub Actions. Perhitungan berjalan di browser Android.

## Aktifkan
1. Buat repository GitHub bernama `aeon` (public untuk penggunaan GitHub Pages pada konfigurasi umum).
2. Unggah seluruh isi folder ini ke root branch `main`.
3. Buka **Settings → Pages → Build and deployment** dan pilih **GitHub Actions**.
4. Buka tab **Actions**, jalankan workflow `Build and deploy AEON Pages` bila belum otomatis berjalan.
5. Setelah deployment sukses, buka URL Pages yang ditampilkan GitHub. Di Android Chrome pilih **Install app** atau **Add to Home screen**.

## Cara kerja
- `src/aeon_wasm.cpp`: inti kalkulasi C++ dengan ABI C sederhana.
- `.github/workflows/pages.yml`: mengompilasi C++ memakai Emscripten, lalu menerbitkan `index.html`, `aeon.js`, dan `aeon.wasm`.
- `index.html`: antarmuka responsif dan memanggil fungsi C++ melalui WebAssembly.

## Batasan
Tidak ada FastAPI, database, Redis, worker server, atau API. Tidak ada sinkronisasi lintas perangkat dan tidak ada simulasi saat browser ditutup. Seluruh kalkulasi berjalan pada perangkat pengguna. Jangan menaruh rahasia atau data sensitif di repository publik.

Solver v0.2.0 menghitung enam besaran sensitivitas skenario saja. Ia belum menyelesaikan dinamika waktu, transfer panas transien R-06→R-04, aliran hidrotermal, neraca massa/energi terkopel, maupun evolusi geokimia. Hasil bukan prediksi ilmiah tervalidasi.
