# 🎥 Kamera Görüntüsü Yakalama Uygulaması

Bu proje, **Qt** ve **OpenCV** kullanılarak geliştirilmiş bir **masaüstü uygulamasıdır**.  
Bilgisayara bağlı kameradan görüntü yakalar ve canlı olarak ekranda gösterir.  
Ayrıca görüntü yakalamayı başlatıp durdurmanıza olanak sağlar.

## 🚀 Özellikler

- Bilgisayardaki kamerayı kullanarak gerçek zamanlı video akışı sağlar.
- Görüntüyü Qt arayüzünde gösterir.
- Başlat ve Durdur butonları ile kamerayı kontrol etme imkanı sunar.
- Kullanıcı dostu ve sade bir arayüz.

## 🛠️ Kullanılan Teknolojiler

- **Programlama Dili**: C++
- **Arayüz**: Qt Framework (Qt Widgets)
- **Görüntü İşleme**: OpenCV
- **Diğer**: QTimer kullanılarak her 30ms'de bir yeni frame çekme


## 🧩 Ana Bileşenler

- **MainWindow**: 
  - Kamera başlatma ve durdurma işlevlerini kontrol eder.
  - Görüntüleri QLabel üzerinde gösterir.
- **QTimer**: 
  - Belirli aralıklarla `updateFrame` fonksiyonunu tetikler.
- **OpenCV**:
  - Kameradan frame çeker ve renk formatını Qt'ye uygun hale getirir.

## 📸 Kullanım

1. Uygulamayı çalıştırın.
2. **Start** butonuna basarak kamera görüntüsünü başlatın.
3. **Stop** butonuna basarak görüntüyü durdurun.

## ⚙️ Kurulum ve Çalıştırma

### Gereksinimler
- Qt 5 veya Qt 6 (Qt Creator önerilir)
- OpenCV kütüphanesi (kurulu olmalı)
- CMake (isteğe bağlı)

### Derleme Adımları
1. Projeyi Qt Creator veya herhangi bir C++ IDE'si ile açın.
2. OpenCV kütüphanesinin doğru şekilde linklendiğinden emin olun.
3. Projeyi build edin ve çalıştırın!

## 📌 Notlar
- Uygulama, bilgisayardaki **varsayılan (0. index)** kamerayı kullanır.
- Kamera açılmazsa ekranda hata mesajı gösterilir.

---


