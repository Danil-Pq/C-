//Задание 1
#include <iostream> 
using namespace std; 
 
int main() { 
    double k, p, r; 
    cout << "Введите сумму кредита (k), процент (p) и прибыль (r): "; 
    cin >> k >> p >> r; 
 
    double totalDebt = k; // Общая сумма долга 
    double annualInterest = (p / 100) * totalDebt; // Годовые проценты 
    double profit = r; // Годовая прибыль 
 
    int years = 0; 
 
    while (totalDebt > 0) { 
        totalDebt += annualInterest; // Увеличиваем долг на проценты 
        totalDebt -= profit; // Уменьшаем долг на прибыль 
        years++; 
 
        if (totalDebt <= 0) { 
            break; // Если долг погашен 
        } 
        else if (annualInterest > r) { 
            break; 
        } 
 
    } 
    if (totalDebt <= 0) { 
        cout << "Кредит будет погашен через " << years << " лет."; 
    }  
    else { 
        cout << "Кредит не будет погашен."; 
        } 
 
    return 0; 
}



//Задание 2
#include <iostream>

int main() {
    int time1, time2, time3;
    int totalTime = 0;

    std::cout << "Введите время обработки деталей (time1 time2 time3) или закончите ввод (введите -1 -1 -1): " << std::endl;

    while (true) {
        std::cin >> time1 >> time2 >> time3;

        // Проверка на завершение ввода
        if (time1 == -1 && time2 == -1 && time3 == -1) {
            break;
        }

        totalTime += time1 + time2 + time3; // суммируем время обработки
    }

    std::cout << "Общее время обработки всех деталей: " << totalTime << " минут." << std::endl;
    return 0;
}



//Задание 3
#include <iostream>

int main() {
    int T; // продолжительность смены
    std::cout << "Введите продолжительность смены (T): ";
    std::cin >> T;

    int t, l; // момент прихода и продолжительность обслуживания
    int servedClients = 0; // количество обслуженных клиентов

    std::cout << "Введите время прихода и длительность обслуживания клиентов (t l) или закончите ввод (введите -1 -1): " << std::endl;

    while (true) {
        std::cin >> t >> l;

        // Проверка на завершение ввода
        if (t == -1 && l == -1) {
            break;
        }

        if (t + l <= T) { // если клиент может быть обслужен в пределах смены
            servedClients++;
            T -= l; // уменьшаем оставшееся время смены
        }
    }

    std::cout << "Мастер обслужит " << servedClients << " клиентов." << std::endl;
    return 0;
}



//Задание 5
#include <iostream>

int main() {
    double u, v, w; // суточный рацион на корову
    double s, t, f; // запасы кормов
    double p, q, r; // проценты потерь

    std::cout << "Введите суточный рацион (u - сено, v - силос, w - комбикорм): ";
    std::cin >> u >> v >> w;

    std::cout << "Введите запасы кормов (s - сено, t - силос, f - комбикорм): ";
    std::cin >> s >> t >> f;

    std::cout << "Введите проценты потерь (p - сено, q - силос, r - комбикорм): ";
    std::cin >> p >> q >> r;

    int days = 0; // дни до истощения кормов

    while (s > 0 && t > 0 && f > 0) {
        // Уменьшаем запасы на суточный рацион
        s -= u;
        t -= v;
        f -= w;

        // Учитываем потери
        s -= s * (p / 100); // потери сена
        t -= t * (q / 100); // потери силоса
        f -= f * (r / 100); // потери комбикорма

        days++; // увеличиваем счетчик дней
    }

    std::cout << "Кормов не хватит через " << days << " дней." << std::endl;

    // Определяем, какой корм закончится первым
    if (s <= 0 && t <= 0 && f <= 0) {
        std::cout << "Все корма закончатся одновременно." << std::endl;
    } else if (s <= 0) {
        std::cout << "Сено кончится первым." << std::endl;
    } else if (t <= 0) {
        std::cout << "Силос кончится первым." << std::endl;
    } else if (f <= 0) {
        std::cout << "Комбикорм кончится первым." << std::endl;
    }

    return 0;
}
