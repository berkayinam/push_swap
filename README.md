# push_swap

42 okulunun algoritma projesi olan push_swap, sınırlı komut seti kullanarak iki yığın arasında sayıları sıralama problemi üzerine odaklanmaktadır.

## 🎯 Proje Hakkında

push_swap projesi, iki yığın (stack) ve sınırlı bir komut seti kullanarak verilen sayı dizisini en az hamle sayısıyla sıralamayı amaçlayan bir algoritmik problemdir. Proje, algoritma optimizasyonu ve veri yapıları konularında derinlemesine anlayış kazandırmayı hedeflemektedir.

## 💻 Teknolojiler

- C Programlama Dili
- Makefile
- Veri Yapıları (Yığınlar)
- Sıralama Algoritmaları

## 🛠️ Kurulum

### Gereksinimler
- GCC Derleyici
- Make
- Shell

### Derleme ve Çalıştırma

1. Projeyi klonlayın:
```bash
git clone https://github.com/[kullanıcı-adı]/push_swap.git
cd push_swap
```

2. Projeyi derleyin:
```bash
make
```

3. Programı çalıştırın:
```bash
./push_swap 5 2 3 1 4
```

4. Checker ile test edin:
```bash
ARG="5 2 3 1 4"; ./push_swap $ARG | ./checker $ARG
```

## 📝 Özellikler

### Temel İşlemler
- [x] sa (swap a): İlk iki elemanı değiştirir - stack a
- [x] sb (swap b): İlk iki elemanı değiştirir - stack b
- [x] ss : sa ve sb aynı anda
- [x] pa (push a): b'nin üstündeki elemanı a'ya taşır
- [x] pb (push b): a'nın üstündeki elemanı b'ye taşır
- [x] ra (rotate a): Yukarı döndürme - stack a
- [x] rb (rotate b): Yukarı döndürme - stack b
- [x] rr : ra ve rb aynı anda
- [x] rra (reverse rotate a): Aşağı döndürme - stack a
- [x] rrb (reverse rotate b): Aşağı döndürme - stack b
- [x] rrr : rra ve rrb aynı anda

### Algoritma Özellikleri
- [x] 3 sayı için özel algoritma
- [x] 5 sayı için özel algoritma
- [x] 100 sayı için optimize edilmiş algoritma
- [x] 500 sayı için optimize edilmiş algoritma
- [x] Hata kontrolü ve argüman doğrulama

## 🎯 42 Proje Gereksinimleri

### Zorunlu Kısım
- [x] İki yığın kullanımı (a ve b)
- [x] Sınırlı komut seti
- [x] Minimum hamle sayısı
- [x] Hata yönetimi
- [x] Bellek yönetimi

### Bonus Özellikler
- [x] Checker programı
- [x] Görsel gösterim
- [x] Hamle sayısı optimizasyonu
- [x] Hata mesajları
- [x] Komut doğrulama

## 🔢 Algoritma Detayları

### Küçük Diziler (≤5)
```c
// 3 sayı için algoritma
void sort_three(t_stack *stack)
{
    if (is_sorted(stack))
        return;
    if (stack->array[0] > stack->array[1])
        sa(stack);
    if (!is_sorted(stack))
        ra(stack);
}
```

### Büyük Diziler
1. Chunk'lara Ayırma
2. Medyan Bulma
3. Optimize Rotasyon
4. Push İşlemleri
5. Final Sıralama

## 📊 Performans Hedefleri

| Sayı Aralığı | Maksimum Hamle |
|--------------|----------------|
| 3 sayı      | 2-3           |
| 5 sayı      | 12            |
| 100 sayı    | 700           |
| 500 sayı    | 5500          |

## 🔍 Test Etme

### Manuel Test
```bash
./push_swap 4 67 3 87 23
```

### Rastgele Sayılar ile Test
```bash
ARG=$(shuf -i 1-100 -n 100 | tr "\n" " "); ./push_swap $ARG | wc -l
```

### Checker ile Test
```bash
ARG=$(shuf -i 1-100 -n 100 | tr "\n" " "); ./push_swap $ARG | ./checker $ARG
```

## 🐛 Hata Ayıklama

### Yaygın Hatalar
1. Argüman Hataları
   - Sayı olmayan girişler
   - Tekrarlanan sayılar
   - INT sınırları dışında değerler

2. Bellek Hataları
   - Bellek sızıntıları
   - Stack taşmaları
   - Geçersiz bellek erişimi

## 📈 Optimizasyon İpuçları

1. Algoritma Optimizasyonu
   - Chunk boyutu optimizasyonu
   - Rotasyon yönü seçimi
   - Push sırası optimizasyonu

2. Kod Optimizasyonu
   - Fonksiyon yeniden kullanımı
   - Bellek yönetimi
   - Koşul kontrolü optimizasyonu

## 🔧 Yardımcı Araçlar

### Görselleştirici
```bash
# Python görselleştirici için
python3 visualizer.py "$(./push_swap 4 67 3 87 23)"
```

### Performans Analizi
```bash
# Hamle sayısı analizi
for i in {1..100}; do
    ARG=$(shuf -i 1-100 -n 100 | tr "\n" " ")
    ./push_swap $ARG | wc -l
done | awk '{ sum += $1 } END { print sum/NR }'
```

## 👥 Katkıda Bulunma

1. Bu repository'yi fork edin
2. Feature branch'i oluşturun (`git checkout -b feature/AmazingFeature`)
3. Değişikliklerinizi commit edin (`git commit -m 'Add some AmazingFeature'`)
4. Branch'inizi push edin (`git push origin feature/AmazingFeature`)
5. Pull Request oluşturun

## 📝 Lisans

Bu proje [MIT](LICENSE) lisansı altında lisanslanmıştır.

## 📚 Kaynaklar

- [Sıralama Algoritmaları](https://www.geeksforgeeks.org/sorting-algorithms/)
- [Yığın Veri Yapısı](https://www.programiz.com/dsa/stack)
- [Big O Notasyonu](https://www.bigocheatsheet.com/)

---

⭐️ Bu projeyi beğendiyseniz yıldız vermeyi unutmayın!
