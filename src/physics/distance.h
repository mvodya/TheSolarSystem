#pragma once

// Значение астрономической единицы (ае)
const double AE = 149597870;

class Distance {
 private:
  int k;

 public:
  Distance(int k = 0);

  // Получение ае
  double ae() { 
    return k / AE; 
  }

  // Получение км
  int km() { 
    return k; 
  }

  // Запись км
  void km(int m) { 
    k = m; 
  };

  // Запись ае
  void ae(double a) { 
    k = a * AE; 
  }
};

Distance::Distance(int k) { this->k = k; }