#include <stdio.h>

// Fonksiyonların tanımları

// Ay ve yıl süresini ekrana yazdırmak için kullanılır.
void print_duration(int months);

// Miktarı ekrana yazdırmak için kullanılır.
void print_money(float amount);

// Kredi ödeme detaylarını ekrana yazdırmak için kullanılır.
void print_entry(float loan_amount, float int_rate, int months);

// Tam raporu ekrana yazdırmak için kullanılır.
void print_full_report(float loan_amount, float int_rate, int max_years, int max_months, int iteration, char *name);

int main() {
    char name[100], wait;  // Kullanıcının adını saklamak için 100 karakterlik bir dizi ve sistem bekletme değişkeni
    float int_rate;  // Yıllık faiz oranı değişkeni
    float loan_amount;  // Kredi miktarı değişkeni
    int max_years;  // Maksimum süre yılı değişkeni
    int max_months;  // Maksimum süre ayı değişkeni
    int iteration;  // Yineleme aralığı değişkeni
    // Kullanıcı arayüzünün karşılama bölümü
    printf("..................................................\n");
    printf(".*.*.*.*.*Welcome to Interest Calculator*.*.*.*.*.\n");
    printf("..................................................\n");
    // Kullanıcıdan adını al
    printf("   Please enter your name: ");
    scanf("%s", name);
    // Gerekli girişleri kullanıcıdan al
    printf("   Loan Amount: ");
    scanf("%f", &loan_amount);
    printf("   Interest rate (per year):");
    scanf("%f", &int_rate);
    printf("   -> TIME LENGTH\n");
    printf("      Loan term in years:");
    scanf("%d", &max_years);
    printf("      Loan term in months:");
    scanf("%d", &max_months);
    printf("      Iteration in months:");
    scanf("%d", &iteration);
    printf(".........................................................");
    print_full_report(loan_amount, int_rate, max_years, max_months, iteration, name);  // Raporu yazdır
    printf("\nThe system is on until you enter a character into the terminal."); scanf("%s",wait);// Sistemi bekletir.
    return 0; }

// Ay ve yıl süresini ekrana yazdırmak için kullanılır.
void print_duration(int months) {
    int years = months / 12;  // Yılları hesaplamak için ay sayısını 12'ye böler
    int remaining_months = months % 12;  // Kalan ayları hesaplamak için ay sayısını 12'ye bölümün kalansız bölümünü alır
    printf("---------------------------------------------------------\n");
    printf("->Year: %d, Month: %d\n", years, remaining_months);
}

// Miktarı ekrana yazdırmak için kullanılır.
void print_money(float amount) {
    float loan_amount = (int)(amount * 10) / 10.0;  // Miktarı ondalık basamağa kadar yuvarlar
    printf("%.1f $\n", loan_amount);
}

// Kredi ödeme detaylarını ekrana yazdırmak için kullanılır.
void print_entry(float loan_amount, float int_rate, int counter_months) {
    float total_interest = (loan_amount / 100) * (int_rate / 12) * counter_months;  // Toplam faiz miktarını hesaplar
    loan_amount = loan_amount + total_interest;  // Faizi kredi miktarına ekler
    printf("Total Payment: ");
    print_money(loan_amount);
    printf("Monthly Payment: ");
    loan_amount = loan_amount / counter_months;  // Aylık ödeme miktarını hesaplar
    print_money(loan_amount);
}

// Tam raporu ekrana yazdırmak için kullanılır.
void print_full_report(float loan_amount, float int_rate, int max_years, int max_months, int iteration, char *name) {
    printf("\nReport for %s:\n", name);
    printf("---------------------------------------------------------\n");
    int total_months = max_years * 12 + max_months;  // Toplam ay sayısını hesaplar

    int counter_month;  // Kontrol sayacı

    for (counter_month = iteration; counter_month <= total_months; counter_month += iteration) {
        print_duration(counter_month);
        printf("--- %d Total Month ---\n", counter_month);
        print_entry(loan_amount, int_rate, counter_month);
    }
}
