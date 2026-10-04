# 4 Ekim 2026: ESP32, Breadboard ve Arduino IDE Ders Notları

---

## İçindekiler

1. [Multimetre (DT830D)](#1-multimetre-dt830d)
2. [İlk program: LED yakıp söndürme](#2-i̇lk-program-led-yakıp-söndürme)
3. [Breadboard kuralları](#3-breadboard-kuralları)
4. [LED ve direnç](#4-led-ve-direnç)
5. [Devre kurulumu](#5-devre-kurulumu)
6. [ESP32 kartı ve pinler](#6-esp32-kartı-ve-pinler)
7. [Donanım kavramları](#7-donanım-kavramları)
8. [Sayaç ve süre programı](#8-sayaç-ve-süre-programı)
9. [Ek: Hızlı komutlar](#ek-hızlı-komutlar)

---

## 1. Multimetre (DT830D)

### Prob bağlantısı
| Prob | Soket |
|---|---|
| Siyah | **COM** |
| Kırmızı | **VΩmA** (ortadaki) |

- **10A** soketi sadece yüksek akım içindir, normal ölçümde kullanılmaz.
- Gerilim ölçerken kırmızı prob mA girişinde olmamalı, yoksa kısa devre/sigorta riski var.

### Ekranda "1" görünmesi
- Ohm modunda sol tarafta **1** = **OL (açık devre)**, yani prob uçları arasında iletim yok.
- Probları değdirince ~0.00 görmek normal.

### Yaşadığım sorun
- Ohm'da "1", DC voltajda da "000" görüldü. Pil ile (1.5V) yaptığım test de sonuç vermedi.
- **Çıkarım:** DT830D'de V ve Ω ölçümleri sigortadan geçmez, bu yüzden sigorta şüphesi düşük. Asıl şüpheliler: **prob kablosu içeriden kopuk** ya da **kırmızı probun yanlış sokette olması**.

### DT830D notları
- Süreklilik (bip) ve diyot **aynı konumda** (▷|).
- Otomatik kapanma yok, kullanınca kadranı **OFF**'a çevir (9V pil gider).
- Pil testi: kadran **DCV 20**, kırmızı → pil (+), siyah → pil (−). Eksi işareti çıkarsa problar ters tutulmuş demektir, zararı yok.
- Şebeke (220V) ölçümü yapma.

---

## 2. İlk program: LED yakıp söndürme

```cpp
const int ledPin = 2;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(1000);
}
```

- Birçok DevKit'te **mavi LED GPIO 2'ye bağlı**, bu yüzden dış devre olmadan da yanıp söner.
- `setup()` bir kez, `loop()` sonsuza kadar tekrar çalışır (ayrıca `for` yazmaya gerek yok).
- `delay(1000)` + `delay(1000)` = **2 saniyelik** döngü (0,5 Hz). Saniyede bir tam yanıp sönme için 500 / 500.

### Denenecek deneyler
- `delay` değerlerini değiştirmek (200, 500...).
- Kısa yanık / uzun sönük: `delay(100)` ve `delay(1900)`.
- Kalp atışı: iki kısa yanıp sönme + uzun bekleme.
- PWM ile parlaklık: `analogWrite(ledPin, 20)` (0-255). Çekirdek 3.x'te çalışır.

### Pin tanımı neden var? (`const int ledPin = 2;`)
- Okunabilirlik: `digitalWrite(ledPin, HIGH)` ne yaptığını anlatır.
- Tek yerden değiştirme: LED başka pine taşınınca sadece o satır değişir.
- `const` = sabit, yanlışlıkla değiştirilirse derleyici hata verir.
- Eski yöntem: `#define LED_PIN 2`

---

## 3. Breadboard kuralları

### Bağlantı yapısı
- Ortadaki oluğun **her yanında**, aynı numaralı sütunda **5'erli gruplar** birbirine bağlıdır:
  - **a-b-c-d-e** → bir düğüm
  - **f-g-h-i-j** → başka bir düğüm
- **e ile f bağlı değildir.** Oluk (orta hat) iki yarıyı ayırır.
- Farklı sütunlar birbirinden bağımsızdır.
- Kenardaki kırmızı (+) / mavi (−) uzun hatlar **yatay** bağlıdır (bazı büyük modellerde ortadan bölünmüş olabilir).

```
         sütun 25
   a ─┐
   b  │
   c  ├─ aynı düğüm (A)
   d  │
   e ─┘
  ═══ oluk ═══
   f ─┐
   g  │
   h  ├─ aynı düğüm (K)
   i  │
   j ─┘
```

### Oluk ne işe yarar?
Standart DIP entegre devrenin iki bacak sırasını birbirinden ayırır. ESP32'nin iki pin sırası da oluğun iki yanına oturur.

### Altın kural
> Bir elemanın **iki ucu aynı gruptaysa** eleman devre dışı kalır (kısa devre).
> **Farklı elemanların birer ucu aynı gruptaysa** onlar birbirine bağlanmış olur. İstenen de budur.

| Durum | Sonuç |
|---|---|
| LED iki bacağı aynı grupta | LED atlanır (kısa devre), yanmaz |
| LED bacakları e ve f (oluğun iki yanı) | ✅ Doğru |
| LED bacakları farklı sütunlarda | ✅ Doğru |
| Direncin iki ucu aynı grupta | Direnç devre dışı, LED korumasız |
| Direnç ucu + LED anot aynı grupta | ✅ İstenen seri bağlantı |

### ESP32'yi breadboard'a takmak
- Kart pinleri iki yana oturur, **bir tarafta boş delik kalmayabilir** (a-e tarafı kapanmıştı).

---

## 4. LED ve direnç

### LED
- **Uzun bacak = anot (+)**, **kısa bacak = katot (−)**.
- Katot tarafında plastik gövde genelde düz kesiktir.
- Ters takılırsa yanmaz, zarar görmez.
- **Direnç olmadan bağlama!**

### Direnç hesabı

R = (V<sub>kaynak</sub> − V<sub>LED</sub>) / I

| LED rengi | Yaklaşık V<sub>LED</sub> |
|---|---|
| Kırmızı | ~2.0 V |
| Sarı / Yeşil | ~2.1 V |
| Mavi / Beyaz | ~3.0 V |

Kırmızı LED, ESP32 (3.3 V), hedef 5-10 mA:
- 10 mA → (3.3 − 2.0) / 0.010 = **130 Ω**
- 5 mA → 1.3 / 0.005 = **260 Ω**

| Direnç | Akım (kırmızı) | Sonuç |
|---|---|---|
| 150 Ω | ~9 mA | Parlak |
| **220 Ω** | ~6 mA | Parlak, güvenli (kullandığım) |
| 330 Ω | ~4 mA | Orta |
| 1 kΩ | ~1.3 mA | Sönük |

### Renk kodu
| Değer | Bantlar |
|---|---|
| 220 Ω | kırmızı-kırmızı-kahverengi |
| 330 Ω | turuncu-turuncu-kahverengi |
| 1 kΩ | kahverengi-siyah-kırmızı |

İlk iki bant rakam, üçüncü bant çarpan, dördüncü bant tolerans. Direncin yönü fark etmez.

### Güvenli akım
- ESP32 pini kağıt üzerinde 20-40 mA verebilir, ama pratikte **~12 mA altında** kalmak iyi.
- Motor, röle gibi büyük yükler için transistör gerekir.

---

## 5. Devre kurulumu

### Şema
```
GPIO 2 ──► 220 Ω direnç ──► LED anot (uzun) ──► LED katot (kısa) ──► GND
```

### Son kurulum (kart çevrildikten sonra)
| Eleman | Konum |
|---|---|
| Direnç | 30d ↔ 35d |
| LED | 35e (anot, uzun) ve 35g (katot) |
| GPIO jumperı | 30a → kartın **D2** pini (4. sütun, pin b satırında, jumper 4a'da) |
| GND jumperı | 35j → kartın **GND** pini (2. sütun, jumper 2a'da) |

Akış: `D2 (4a/4b) → 30a → direnç → 35d/35e (anot) → LED → 35g/35j (katot) → 2a/2b (GND)`

### Dersler
- **Dişi jumper ucu gevşek temas yapabilir.** İlk denemede LED'in yanmamasının sebebi buydu. Değiştirince/sıkıştırınca düzeldi.
- Üst sıradaki GND ile alt sıradaki GND **aynı noktadır** (kart içinde bağlı), farklı sıradan kullanmak sorun değil.
- Bu devre GPIO 2'yi mavi LED ile **paylaşır**, ikisi birlikte yanıp söner.
- Önce USB'yi çıkar, sonra bağlantı yap.

### Yanmazsa kontrol sırası
1. LED yönü
2. Jumper uçları ve direnç tam oturmuş mu?
3. Dişi uç D2'ye tam oturuyor mu, komşu pine (D15, D4) kaymadı mı?
4. D2 ve GND sütun numaraları doğru mu? GND yanında 3V3 ve VIN var, sütun kaymasına dikkat.
5. Pin ile jumper **aynı 5'li grupta** mı?

---

## 6. ESP32 kartı ve pinler

### Çip özellikleri (klasik ESP32)
- **CPU:** Xtensa LX6, çift çekirdek, 240 MHz'e kadar
- **SRAM:** 520 KB (Wi-Fi açıkken boş heap ~200-300 KB)
- **Flash:** genelde 4 MB, çipin dışında (modül içinde)
- **Kablosuz:** Wi-Fi (2.4 GHz) + Bluetooth/BLE
- **GPIO:** ~25-30 kullanılabilir
- **Çevre birimleri:** 3 UART, 2 I2C, SPI, ADC, DAC, PWM, dokunmatik pinler, 4 timer
- **Çalışma gerilimi: 3.3 V.** Pinler 5 V'a dayanıklı değildir.
- **Deep sleep:** mikroamper seviyesi

### Kart üzerindeki parçalar
| Parça | Görev |
|---|---|
| ESP32 modülü (metal kalkan) | Beyin: çip + flash + kristal + anten |
| **CP2102** (SLABS) | USB ↔ UART köprüsü; PC ile konuşmayı sağlar |
| AMS1117-3.3 (3 bacaklı) | 5 V'u 3.3 V'a düşürür; 3V3 pininin kaynağı |
| Otomatik reset devresi | DTR/RTS ile kendiliğinden yükleme moduna sokar |
| **EN** tuşu | Reset |
| **BOOT** tuşu (GPIO 0) | Basılı tutarak resetlersen yükleme moduna girer |
| Kırmızı LED | Güç LED'i |
| Mavi LED | GPIO 2'ye bağlı |

### GPIO numarası nedir?
- Kodda `2`, kartın sıra numarası değil **çipin GPIO 2 kanalıdır**. Breadboard sütun numarasıyla ilgisi yok.
- `pinMode(2, OUTPUT)` → GPIO 2'nin yön register'ına yazar.
- `digitalWrite(2, HIGH)` → pin 3.3 V olur.

### Dikkat edilecek pinler
- **GPIO 34-39:** sadece giriş.
- **GPIO 0, 2, 12, 15:** boot sırasında özel anlamı olan (strapping) pinler. GPIO 2 LED için sorun çıkarmaz.
- Wi-Fi açıkken **ADC2** pinleri çalışmaz.

### Kartımın pin sırası (kendi okumam)
- Üst sıra: VIN, GND, D13, D12, D14, ...
- Alt sıra: 3V3, GND, D15, **D2**, D0, D4, ...

> Kartın üzerindeki yazıları her zaman kendi gözümle doğrulamalıyım; farklı kartlarda dizilim değişir.

### 📝 Notlarım
-

---

## 7. Donanım kavramları

### ASIC / FPGA / MCU
| | ASIC (ör. ESP32) | FPGA | Genel MCU |
|---|---|---|---|
| Donanım | Üretimde sabitlenir | Yeniden yapılandırılabilir | Sabit, yazılımla programlanır |
| Birim fiyat (yüksek adet) | Çok düşük | Yüksek | Düşük |
| İlk yatırım (NRE) | Çok yüksek | Düşük | Yok |
| Güç verimliliği | En iyi | Daha kötü | İyi |

- ESP32 teknik olarak bir ASIC ama kullanıcı olarak **MCU gibi** kullanılır.
- Espressif **fabless**; üretim TSMC gibi foundry'lerde yapılır.
- Çip küçüktür (QFN48, ~5×5 mm). Büyük görünen şey kart, modül, USB soketi ve pin başlıklarıdır.
- GDS dosyaları (çip maske tasarımı) **gizlidir**, herkese açık değil. Açık kaynak örnekler için SkyWater 130 nm, Tiny Tapeout; görüntülemek için KLayout.

### SoC mi MCU mu?
- **MCU:** CPU + flash + SRAM + çevre birimleri tek çipte; gerçek zamanlı kontrol için.
- **SoC:** bir sistemin çoğunu tek silikona toplama yaklaşımı (telefon işlemcileri, RPi çipi gibi).
- ESP32 ikisi de: çalışma tarzı MCU, entegrasyon düzeyi SoC.

### "Programlanabilir" ne demek?
Davranışın bir kısmı **devrenin yapısından çıkıp veriye (koda) taşınmıştır.**

Çalışma döngüsü:
1. **Program counter** adres üretir.
2. O adresten **komut** okunur (komut = bir sayı).
3. **Decoder** sayıya bakıp devrenin ilgili yollarını açar/kapar.
4. **ALU** işlemi yapar, sonuç **register**'a yazılır.
5. Program counter bir sonraki adrese geçer.

Gerekli donanım: **CPU (decoder + ALU + register + PC)** + **yeniden yazılabilir program belleği (flash)** + **veri belleği (SRAM)** + **bus'lar** + register ile kontrol edilen **çevre birimleri**.

- **CP2102 gibi sabit çiplerde** komut çalıştıran, kullanıcı kodu alan CPU yok. Sadece EEPROM'daki VID/PID gibi ayarlar değiştirilebilir.
- CP2102'de AI hızlandırıcı, I2C, QSPI, SPI, ADC, PWM yok.
- Klasik ESP32 **Xtensa**'dır. RISC-V olanlar: ESP32-C3, C6, H2. ESP32-S2/S3 de Xtensa.

### Bellek: program nerede durur?
| Bellek | Kalıcı mı? | İçeriği |
|---|---|---|
| **Flash** (4 MB, dışarıda) | Evet | Program kodu |
| **SRAM** (520 KB, çip içinde) | Hayır (uçucu) | Değişkenler, stack, heap |
| **Cache** | Hayır | Flash'tan çekilen sık kullanılan kod |
| **IRAM** (SRAM'in bir kısmı) | Hayır | `IRAM_ATTR` ile hızlı/kritik fonksiyonlar |
| **ROM** | Evet | Sabit bootloader |

Açılış zinciri: ROM bootloader → flash'taki program → cache üzerinden çalışma + SRAM'de değişkenler. Kod flash'tan çalışmaya devam eder (**XIP**, execute in place).

---

## 8. Sayaç ve süre programı

Hedef: LED her yanıp sönmede sayaç artsın, geçen süre Serial Monitor'a yazılsın.

### Son hâl
```cpp
// ===== Pin tanımı =====
const int ledPin = 2;

// ===== Global değişkenler =====
unsigned long count = 0;   // yanıp sönme sayısı
unsigned long Ctime = 0;   // başlangıç zamanı (ms)

void setup() {
  Serial.begin(115200);    // seri haberleşme, Serial Monitor ile aynı hız olmalı
  pinMode(ledPin, OUTPUT);
  Ctime = millis();        // başlangıç zamanını kaydet
}

void loop() {
  // --- LED yanık aşaması ---
  digitalWrite(ledPin, HIGH);
  delay(500);

  // --- LED sönük aşaması ---
  digitalWrite(ledPin, LOW);
  delay(500);

  count++;

  unsigned long a = millis() - Ctime;   // geçen süre (ms)
  Serial.print("Sayac: ");
  Serial.print(count);
  Serial.print(" | Gecen sure: ");
  Serial.print(int(a / 1000));
  Serial.println(" sn");
}
```

### Serial Monitor
- **Tools > Serial Monitor** (`Ctrl+Shift+M`), hız **115200 baud**.
- Beklenen çıktı:
```
  Sayac: 1 | Gecen sure: 1 sn
  Sayac: 2 | Gecen sure: 2 sn
```
- Terminalden izleme (IDE'deki Serial Monitor kapalıyken):
```bash
  screen /dev/ttyUSB0 115200     # çıkış: Ctrl+A, K, y
```

---

## Ek: Hızlı komutlar

```bash
# Port kontrol
ls /dev/ttyUSB*
sudo dmesg | tail -20

# Grup kontrol
groups
getent group dialout

# Arduino IDE (sandbox sorunluysa)
./arduino-ide_*_Linux_64bit.AppImage --no-sandbox

# Serial izleme
screen /dev/ttyUSB0 115200
```
