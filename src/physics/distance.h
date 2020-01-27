#pragma once

// Значение астрономической единицы (ае)
const double AE = 149597870;

// Коэффициент для перевода в пиксели
const double kp;

class Distance {
 private:
  double k;

 public:
  Distance(double k = 0);

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

Distance::Distance(double k) { this->k = k; }