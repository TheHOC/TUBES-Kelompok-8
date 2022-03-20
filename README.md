# Tugas Besar SEKURO 2022 Divisi Pemrograman - Kelompok 8

GitHub: https://github.com/TheHOC/TUBES-Kelompok-8

## Permainan Mecha-Kurama
Permainan ini memiliki konsep yang mirip dengan _Snake Xenzia_, dimana pemain hanya perlu menaikkan skor sampai kondisi dimana tidak bisa menambahkan skor kembali.

## How-to-Play
Pada permainan ini, pemain berperan sebagai Robot yang bertugas membasmi _bunshin_/bayangan dari Mecha-Kurama. Robot dapat melakukan dua hal: berpindah tempat atau melakukan serangan.

Untuk berpindah tempat, pilih opsi untuk berpindah tempat ketika mendapatkan giliran. Robot dapat berpindah ke atas-kanan-kiri-bawah. Namun pada kondisi tertentu, Robot tidak dapat berpindah ke beberapa arah, seperti terhalang tembok (#) atau Mecha Kurama.

Untuk menyerang, Robot memiliki dua opsi: menyerang sekitar dengan _damage_ yang lebih besar atau menyerang jarak jauh dengan _damage_ yang lebih kecil. Ketika tidak ada Mecha Kurama dalam rentang _range_ serangan, akan muncul pesan bahwa tidak ada yang terkena serangan, namun permainan terus berlanjut (dengan kata lain, pemain seolah-olah kehilangan giliran).

Giliran gerak akan bergantian antara Robot dengan Mecha Kurama. Bisa ada banyak Mecha-Kurama yang ada dalam satu permainan.

Permainan akan berakhir ketika nyawa/_health_ dari Robot habis. Program juga akan menampilkan jumlah Mecha Kurama yang telah dikalahkan.