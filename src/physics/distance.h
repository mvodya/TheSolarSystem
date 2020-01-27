#pragma once

// Значение астрономической единицы (ае)
const double AE = 149597870;

// Коэффициент для перевода в пиксели
const double kp = 1;

class Distance {
 private:
  double k;

 public:
  Distance(double k = 0) { this->k = k; };

  // Получение ае
  double ae() { 
    return k / AE; 
  }

  // Получение км
  double km() { 
    return k; 
  }

  // Запись км
  void km(double m) { 
    k = m; 
  };

  // Запись ае
  void ae(double a) { 
    k = a * AE; 
  }

  // Перевод в пиксели 
  double pix() {
    return k * kp;
  }
};