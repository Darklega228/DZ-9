#include <iostream>
#include <string>
using namespace std;

class Pizza {
    int weight;
    int radius;

    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

public:
    explicit Pizza() : Pizza(0, 1) {}

    explicit Pizza(double decimal) : Pizza() {
        radius = 1;
        while (decimal != (int)decimal) {
            decimal *= 10;
            radius *= 10;
        }
        weight = (int)decimal;
        reduce();
    }

    explicit Pizza(int weig, int rad) {
        setWeight(weig);
        setRadius(rad);
    }

    void setWeight(int weig) {
        weight = weig;
    }

    void setRadius(int rad) {
        if (rad == 0) {
            throw "Знаменатель не может быть нулём.";
        }
        radius = rad;
    }

    int getWeight() const { return weight; }

    int getRadius() const { return radius; }

    void display() const {
        cout << weight << "/" << radius << "\n";
    }

    double toDouble() const {
        return (double)(weight) / radius;
    }

    void reduce() {
        int divisor = gcd(weight, radius);
        weight /= divisor;
        radius /= divisor;

        if (radius < 0) {
            weight = -weight;
            radius = -radius;
        }
    }

    Pizza add(const Pizza& other) const {
        return Pizza(weight * other.radius + other.weight * radius,
            radius * other.weight);
    }

    Pizza subtract(const Pizza& other) const {
        return Pizza(weight * other.radius - other.weight * radius,
            radius * other.radius);
    }

    Pizza multiply(const Pizza& other) const {
        return Pizza(weight * other.weight, radius * other.radius);
    }

    Pizza divide(const Pizza& other) const {
        if (other.weight == 0) {
            throw invalid_argument("Делить на ноль нельзя.");
        }
        return Pizza(weight * other.radius, radius * other.weight);
    }

    bool equals(const Pizza& other) const {
        return weight == other.weight && radius == other.radius;
    }

    bool notEquals(const Pizza& other) const {
        return !equals(other);
    }

    friend Pizza operator + (const Pizza& left, const Pizza& right);
    friend Pizza operator - (const Pizza& original);
    friend Pizza operator + (const Pizza& left, int right);
    friend Pizza operator + (int left, const Pizza& right);

    Pizza operator + (const Pizza& right) {
        cout << "CLASS METHOD OPERATOR + \n";
        Pizza result;
        result.weight = this->weight * right.radius + this->radius * right.weight;
        result.radius = this->radius * right.radius;
        result.reduce();
        return result;
    }

    Pizza operator + (int right) {
        cout << "CLASS METHOD OPERATOR + (F, int)\n";
        Pizza result;
        result.weight = this->weight * 1 + this->radius * right;
        result.radius = this->radius * 1;
        result.reduce();
        return result;
    }

    friend const istream& operator >> (const istream& i, Pizza& f);
    friend const ostream& operator << (const ostream& o, const Pizza& f);

    // метод класса для ЯВНОГО преобразования от ИНТА к Дроби
    explicit operator int(/*const Fraction* this*/)
    { // ТВЗ для такой перегрузки не пишется, компилятор понимает, что нужно получить инт в результате
        cout << "Casting from Pizza to int\n";
        return this->weight / this->radius;
    }

    explicit operator double()
    {
        cout << "Casting from Pizza to double\n";
        return toDouble();
    }

    explicit operator string()
    {
        cout << "Casting from Pizza to string\n";
        return to_string(weight) + " / " + to_string(radius);
    }
};

Pizza operator + (const Pizza& left, const Pizza& right) {
    cout << "GLOBAL FUNCTION OPERATOR + (F, F)\n";
    Pizza result;
    result.weight = left.weight * right.radius + left.radius * right.weight;
    result.radius = left.radius * right.radius;
    result.reduce();
    return result;
}

Pizza operator + (const Pizza& left, int right) {
    cout << "GLOBAL FUNCTION OPERATOR + (F, int)\n";
    Pizza result;
    result.weight = left.weight * 1 + left.radius * right;
    result.radius = left.radius * 1;
    result.reduce();
    return result;
}

Pizza operator + (int left, const Pizza& right) {
    cout << "GLOBAL FUNCTION OPERATOR + (int, F)\n";
    Pizza result;
    result.weight = left * right.radius + 1 * right.weight;
    result.radius = 1 * right.radius;
    result.reduce();
    return result;
}

bool operator > (const Pizza& left, const Pizza& right) {
    cout << "Pizza > Pizza\n";
    return left.toDouble() > right.toDouble();
}

bool operator == (const Pizza& left, const Pizza& right) {
    cout << "Pizza == Pizza\n";
    return left.toDouble() == right.toDouble();
}

bool operator != (const Pizza& left, const Pizza& right) {
    cout << "Pizza != Pizza\n";
    return !(left == right);
}

Pizza operator - (const Pizza& original) {
    Pizza result;
    result.weight = -original.weight;
    result.radius = original.radius;
    return result;
}

const istream& operator >> (const istream& i, Pizza& f) {
    cout << "OP >>\n";
    cout << "Please, enter weight: ";
    cin >> f.weight;
    cout << "Please, enter radius: ";
    cin >> f.radius;
    return i;
}

const ostream& operator << (const ostream& i, const Pizza& f) {
    cout << "OP <<\n";
    f.display();
    return i;
}

class Tower {
    int Bricks;
    int Bucketofcement;

    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

public:
    explicit Tower() : Tower(0, 1) {}

    explicit Tower(double decimal) : Tower() {
        Bucketofcement = 1;
        while (decimal != (int)decimal) {
            decimal *= 10;
            Bucketofcement *= 10;
        }
        Bricks = (int)decimal;
        reduce();
    }

    explicit Tower(int brick, int cem) {
        setBricks(brick);
        setBucketofcement(cem);
    }

    void setBricks(int brick) {
        Bricks = brick;
    }

    void setBucketofcement(int cem) {
        if (cem == 0) {
            throw "Знаменатель не может быть нулём.";
        }
        Bucketofcement = cem;
    }

    int getBricks() const { return Bricks; }

    int getBucketofcement() const { return Bucketofcement; }

    void display() const {
        cout << Bricks << "/" << Bucketofcement << "\n";
    }

    double toDouble() const {
        return (double)(Bricks) / Bucketofcement;
    }

    void reduce() {
        int divisor = gcd(Bricks, Bucketofcement);
        Bricks /= divisor;
        Bucketofcement /= divisor;

        if (Bucketofcement < 0) {
            Bricks = -Bricks;
            Bucketofcement = -Bucketofcement;
        }
    }

    Tower add(const Tower& other) const {
        return Tower(Bricks * other.Bucketofcement + other.Bricks * Bucketofcement,
            Bucketofcement * other.Bricks);
    }

    Tower subtract(const Tower& other) const {
        return Tower(Bricks * other.Bucketofcement - other.Bricks * Bucketofcement,
            Bucketofcement * other.Bucketofcement);
    }

    Tower multiply(const Tower& other) const {
        return Tower(Bricks * other.Bricks, Bucketofcement * other.Bucketofcement);
    }

    Tower divide(const Tower& other) const {
        if (other.Bricks == 0) {
            throw invalid_argument("Делить на ноль нельзя.");
        }
        return Tower(Bricks * other.Bucketofcement, Bucketofcement * other.Bricks);
    }

    bool equals(const Tower& other) const {
        return Bricks == other.Bricks && Bucketofcement == other.Bucketofcement;
    }

    bool notEquals(const Tower& other) const {
        return !equals(other);
    }

    friend Tower operator + (const Tower& left, const Tower& right);
    friend Tower operator - (const Tower& original);
    friend Tower operator + (const Tower& left, int right);
    friend Tower operator + (int left, const Tower& right);

    Tower operator + (const Tower& right) {
        cout << "CLASS METHOD OPERATOR + \n";
        Tower result;
        result.Bricks = this->Bricks * right.Bucketofcement + this->Bucketofcement * right.Bricks;
        result.Bucketofcement = this->Bucketofcement * right.Bucketofcement;
        result.reduce();
        return result;
    }

    Tower operator + (int right) {
        cout << "CLASS METHOD OPERATOR + (F, int)\n";
        Tower result;
        result.Bricks = this->Bricks * 1 + this->Bucketofcement * right;
        result.Bucketofcement = this->Bucketofcement * 1;
        result.reduce();
        return result;
    }

    friend const istream& operator >> (const istream& i, Tower& f);
    friend const ostream& operator << (const ostream& o, const Tower& f);

    // метод класса для ЯВНОГО преобразования от ИНТА к Дроби
    explicit operator int(/*const Fraction* this*/)
    { // ТВЗ для такой перегрузки не пишется, компилятор понимает, что нужно получить инт в результате
        cout << "Casting from Tower to int\n";
        return this->Bricks / this->Bucketofcement;
    }

    explicit operator double()
    {
        cout << "Casting from Tower to double\n";
        return toDouble();
    }

    explicit operator string()
    {
        cout << "Casting from Tower to string\n";
        return to_string(Bricks) + " / " + to_string(Bucketofcement);
    }
};

Tower operator + (const Tower& left, const Tower& right) {
    cout << "GLOBAL FUNCTION OPERATOR + (F, F)\n";
    Tower result;
    result.Bricks = left.Bricks * right.Bucketofcement + left.Bucketofcement * right.Bricks;
    result.Bucketofcement = left.Bucketofcement * right.Bucketofcement;
    result.reduce();
    return result;
}

Tower operator + (const Tower& left, int right) {
    cout << "GLOBAL FUNCTION OPERATOR + (F, int)\n";
    Tower result;
    result.Bricks = left.Bricks * 1 + left.Bucketofcement * right;
    result.Bucketofcement = left.Bucketofcement * 1;
    result.reduce();
    return result;
}

Tower operator + (int left, const Tower& right) {
    cout << "GLOBAL FUNCTION OPERATOR + (int, F)\n";
    Tower result;
    result.Bricks = left * right.Bucketofcement + 1 * right.Bricks;
    result.Bucketofcement = 1 * right.Bucketofcement;
    result.reduce();
    return result;
}

bool operator > (const Tower& left, const Tower& right) {
    cout << "Tower > Tower\n";
    return left.toDouble() > right.toDouble();
}

bool operator == (const Tower& left, const Tower& right) {
    cout << "Tower == Tower\n";
    return left.toDouble() == right.toDouble();
}

bool operator != (const Tower& left, const Tower& right) {
    cout << "Tower != Tower\n";
    return !(left == right);
}

Tower operator - (const Tower& original) {
    Tower result;
    result.Bricks = -original.Bricks;
    result.Bucketofcement = original.Bucketofcement;
    return result;
}

const istream& operator >> (const istream& i, Tower& t) {
    cout << "OP >>\n";
    cout << "Please, enter Bricks: ";
    cin >> t.Bricks;
    cout << "Please, enter Bucket of cement: ";
    cin >> t.Bucketofcement;
    return i;
}

const ostream& operator << (const ostream& i, const Tower& t) {
    cout << "OP <<\n";
    t.display();
    return i;
}

class SentinelPrime {
    int Torso;
    int genitals;

    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

public:
    explicit SentinelPrime() : SentinelPrime(0, 1) {}

    explicit SentinelPrime(double decimal) : SentinelPrime() {
        genitals = 1;
        while (decimal != (int)decimal) {
            decimal *= 10;
            genitals *= 10;
        }
        Torso = (int)decimal;
        reduce();
    }

    explicit SentinelPrime(int Tors, int gen) {
        setTorso(Tors);
        setGenitals(gen);
    }

    void setTorso(int Tors) {
        Torso = Tors;
    }

    void setGenitals(int gen) {
        if (gen == 0) {
            throw "Знаменатель не может быть нулём.";
        }
        genitals = gen;
    }

    int getTorso() const { return Torso; }

    int getGenitals() const { return genitals; }

    void display() const {
        cout << Torso << "/" << genitals << "\n";
    }

    double toDouble() const {
        return (double)(Torso) / genitals;
    }

    void reduce() {
        int divisor = gcd(Torso, genitals);
        Torso /= divisor;
        genitals /= divisor;

        if (genitals < 0) {
            Torso = -Torso;
            genitals = -genitals;
        }
    }

    SentinelPrime add(const SentinelPrime& other) const {
        return SentinelPrime(Torso * other.genitals + other.Torso * genitals,
            genitals * other.Torso);
    }

    SentinelPrime subtract(const SentinelPrime& other) const {
        return SentinelPrime(Torso * other.genitals - other.Torso * genitals,
            genitals * other.genitals);
    }

    SentinelPrime multiply(const SentinelPrime& other) const {
        return SentinelPrime(Torso * other.Torso, genitals * other.genitals);
    }

    SentinelPrime divide(const SentinelPrime& other) const {
        if (other.Torso == 0) {
            throw invalid_argument("Делить на ноль нельзя.");
        }
        return SentinelPrime(Torso * other.genitals, genitals * other.Torso);
    }

    bool equals(const SentinelPrime& other) const {
        return Torso == other.Torso && genitals == other.genitals;
    }

    bool notEquals(const SentinelPrime& other) const {
        return !equals(other);
    }

    friend SentinelPrime operator + (const SentinelPrime& left, const SentinelPrime& right);
    friend SentinelPrime operator - (const SentinelPrime& original);
    friend SentinelPrime operator + (const SentinelPrime& left, int right);
    friend SentinelPrime operator + (int left, const SentinelPrime& right);

    SentinelPrime operator + (const SentinelPrime& right) {
        cout << "CLASS METHOD OPERATOR + \n";
        SentinelPrime result;
        result.Torso = this->Torso * right.genitals + this->genitals * right.Torso;
        result.genitals = this->genitals * right.genitals;
        result.reduce();
        return result;
    }

    SentinelPrime operator + (int right) {
        cout << "CLASS METHOD OPERATOR + (F, int)\n";
        SentinelPrime result;
        result.Torso = this->Torso * 1 + this->genitals * right;
        result.genitals = this->genitals * 1;
        result.reduce();
        return result;
    }

    friend const istream& operator >> (const istream& i, SentinelPrime& f);
    friend const ostream& operator << (const ostream& o, const SentinelPrime& f);

    // метод класса для ЯВНОГО преобразования от ИНТА к Дроби
    explicit operator int(/*const Fraction* this*/)
    { // ТВЗ для такой перегрузки не пишется, компилятор понимает, что нужно получить инт в результате
        cout << "Casting from Sentinel Prime to int\n";
        return this->Torso / this->genitals;
    }

    explicit operator double()
    {
        cout << "Casting from Sentinel Prime to double\n";
        return toDouble();
    }

    explicit operator string()
    {
        cout << "Casting from Sentinel Prime to string\n";
        return to_string(Torso) + " / " + to_string(genitals);
    }
};

SentinelPrime operator + (const SentinelPrime& left, const SentinelPrime& right) {
    cout << "GLOBAL FUNCTION OPERATOR + (F, F)\n";
    SentinelPrime result;
    result.Torso = left.Torso * right.genitals + left.genitals * right.Torso;
    result.genitals = left.genitals * right.genitals;
    result.reduce();
    return result;
}

SentinelPrime operator + (const SentinelPrime& left, int right) {
    cout << "GLOBAL FUNCTION OPERATOR + (F, int)\n";
    SentinelPrime result;
    result.Torso = left.Torso * 1 + left.genitals * right;
    result.genitals = left.genitals * 1;
    result.reduce();
    return result;
}

SentinelPrime operator + (int left, const SentinelPrime& right) {
    cout << "GLOBAL FUNCTION OPERATOR + (int, F)\n";
    SentinelPrime result;
    result.Torso = left * right.genitals + 1 * right.Torso;
    result.genitals = 1 * right.genitals;
    result.reduce();
    return result;
}

bool operator > (const SentinelPrime& left, const SentinelPrime& right) {
    cout << "SentinelPrime > SentinelPrime\n";
    return left.toDouble() > right.toDouble();
}

bool operator == (const SentinelPrime& left, const SentinelPrime& right) {
    cout << "SentinelPrime == SentinelPrime\n";
    return left.toDouble() == right.toDouble();
}

bool operator != (const SentinelPrime& left, const SentinelPrime& right) {
    cout << "SentinelPrime != SentinelPrime\n";
    return !(left == right);
}

SentinelPrime operator - (const SentinelPrime& original) {
    SentinelPrime result;
    result.Torso = -original.Torso;
    result.genitals = original.genitals;
    return result;
}

const istream& operator >> (const istream& i, SentinelPrime& t) {
    cout << "OP >>\n";
    cout << "Please, enter Torso: ";
    cin >> t.Torso;
    cout << "Please, enter genitals: ";
    cin >> t.genitals;
    return i;
}

const ostream& operator << (const ostream& i, const SentinelPrime& t) {
    cout << "OP <<\n";
    t.display();
    return i;
}

class Apple {
    int shell;
    int seed;

    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

public:
    explicit Apple() : Apple(0, 1) {}

    explicit Apple(double decimal) : Apple() {
        seed = 1;
        while (decimal != (int)decimal) {
            decimal *= 10;
            seed *= 10;
        }
        shell = (int)decimal;
        reduce();
    }

    explicit Apple(int shel, int sed) {
        setShell(shel);
        setSeed(sed);
    }

    void setShell(int shel) {
        shell = shel;
    }

    void setSeed(int sed) {
        if (sed == 0) {
            throw "Знаменатель не может быть нулём.";
        }
        seed = sed;
    }

    int getShell() const { return shell; }

    int getSeed() const { return seed; }

    void display() const {
        cout << shell << "/" << seed << "\n";
    }

    double toDouble() const {
        return (double)(shell) / seed;
    }

    void reduce() {
        int divisor = gcd(shell, seed);
        shell /= divisor;
        seed /= divisor;

        if (seed < 0) {
            shell = -shell;
            seed = -seed;
        }
    }

    Apple add(const Apple& other) const {
        return Apple(shell * other.seed + other.shell * seed,
            seed * other.shell);
    }

    Apple subtract(const Apple& other) const {
        return Apple(shell * other.seed - other.shell * seed,
            seed * other.seed);
    }

    Apple multiply(const Apple& other) const {
        return Apple(shell * other.shell, seed * other.seed);
    }

    Apple divide(const Apple& other) const {
        if (other.shell == 0) {
            throw invalid_argument("Делить на ноль нельзя.");
        }
        return Apple(shell * other.seed, seed * other.shell);
    }

    bool equals(const Apple& other) const {
        return shell == other.shell && seed == other.seed;
    }

    bool notEquals(const Apple& other) const {
        return !equals(other);
    }

    friend Apple operator + (const Apple& left, const Apple& right);
    friend Apple operator - (const Apple& original);
    friend Apple operator + (const Apple& left, int right);
    friend Apple operator + (int left, const Apple& right);

    Apple operator + (const Apple& right) {
        cout << "CLASS METHOD OPERATOR + \n";
        Apple result;
        result.shell = this->shell * right.seed + this->seed * right.shell;
        result.seed = this->seed * right.seed;
        result.reduce();
        return result;
    }

    Apple operator + (int right) {
        cout << "CLASS METHOD OPERATOR + (F, int)\n";
        Apple result;
        result.shell = this->shell * 1 + this->seed * right;
        result.seed = this->seed * 1;
        result.reduce();
        return result;
    }

    friend const istream& operator >> (const istream& i, Apple& f);
    friend const ostream& operator << (const ostream& o, const Apple& f);

    // метод класса для ЯВНОГО преобразования от ИНТА к Дроби
    explicit operator int(/*const Fraction* this*/)
    { // ТВЗ для такой перегрузки не пишется, компилятор понимает, что нужно получить инт в результате
        cout << "Casting from Apple to int\n";
        return this->shell / this->seed;
    }

    explicit operator double()
    {
        cout << "Casting from Apple to double\n";
        return toDouble();
    }

    explicit operator string()
    {
        cout << "Casting from Apple to string\n";
        return to_string(shell) + " / " + to_string(seed);
    }
};

Apple operator + (const Apple& left, const Apple& right) {
    cout << "GLOBAL FUNCTION OPERATOR + (F, F)\n";
    Apple result;
    result.shell = left.shell * right.seed + left.seed * right.shell;
    result.seed = left.seed * right.seed;
    result.reduce();
    return result;
}

Apple operator + (const Apple& left, int right) {
    cout << "GLOBAL FUNCTION OPERATOR + (F, int)\n";
    Apple result;
    result.shell = left.shell * 1 + left.seed * right;
    result.seed = left.seed * 1;
    result.reduce();
    return result;
}

Apple operator + (int left, const Apple& right) {
    cout << "GLOBAL FUNCTION OPERATOR + (int, F)\n";
    Apple result;
    result.shell = left * right.seed + 1 * right.shell;
    result.seed = 1 * right.seed;
    result.reduce();
    return result;
}

bool operator > (const Apple& left, const Apple& right) {
    cout << "Apple > Apple\n";
    return left.toDouble() > right.toDouble();
}

bool operator == (const Apple& left, const Apple& right) {
    cout << "Apple == Apple\n";
    return left.toDouble() == right.toDouble();
}

bool operator != (const Apple& left, const Apple& right) {
    cout << "Apple != Apple\n";
    return !(left == right);
}

Apple operator - (const Apple& original) {
    Apple result;
    result.shell = -original.shell;
    result.seed = original.seed;
    return result;
}

const istream& operator >> (const istream& i, Apple& a) {
    cout << "OP >>\n";
    cout << "Please, enter shell: ";
    cin >> a.shell;
    cout << "Please, enter seed: ";
    cin >> a.seed;
    return i;
}

const ostream& operator << (const ostream& i, const Apple& a) {
    cout << "OP <<\n";
    a.display();
    return i;
}

int main() {
    setlocale(0, "");

    /*Pizza f(11, 5); // 3/2 == 1.5
    cout << (int)f << "\n"; // 2
    cout << (double)f << "\n"; // 2.2
    cout << (string)f << "\n"; // "11 / 5"*/

    /*Tower t(11, 5); // 3/2 == 1.5
    cout << (int)t << "\n"; // 2
    cout << (double)t << "\n"; // 2.2
    cout << (string)t << "\n"; // "11 / 5"*/

    /*SentinelPrime SP(10, 5);
    cout << (int)SP << "\n"; // 2
    cout << (double)SP << "\n"; // 2
    cout << (string)SP << "\n"; // "10 / 5"*/

    Apple a(15, 5);
    cout << (int)a << "\n"; // 3
    cout << (double)a << "\n"; // 3
    cout << (string)a << "\n"; // "15 / 5"
}