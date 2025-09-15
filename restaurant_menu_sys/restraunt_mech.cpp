#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <optional>
#include <algorithm>
#include <iomanip>
using namespace std;

struct MenuItem {
    string name;
    string category;
    double price{};
    string description;
};

class Menu {
public:
    bool addItem(const MenuItem& item) {
        auto [it, inserted] = items.emplace(item.name, item);
        if (!inserted) return false;
        byCategory[item.category].push_back(item.name);
        return true;
    }

    bool updatePrice(const string& name, double newPrice) {
        auto it = items.find(name);
        if (it == items.end()) return false;
        it->second.price = newPrice;
        return true;
    }

    bool updateDescription(const string& name, string desc) {
        auto it = items.find(name);
        if (it == items.end()) return false;
        it->second.description = move(desc);
        return true;
    }

    bool recategorize(const string& name, const string& newCategory) {
        auto it = items.find(name);
        if (it == items.end()) return false;

        auto& vec = byCategory[it->second.category];
        vec.erase(remove(vec.begin(), vec.end(), name), vec.end());

        it->second.category = newCategory;
        byCategory[newCategory].push_back(name);
        return true;
    }

    bool removeItem(const string& name) {
        auto it = items.find(name);
        if (it == items.end()) return false;
        auto& vec = byCategory[it->second.category];
        vec.erase(remove(vec.begin(), vec.end(), name), vec.end());
        items.erase(it);
        return true;
    }

    optional<MenuItem> find(const string& name) const {
        auto it = items.find(name);
        if (it == items.end()) return nullopt;
        return it->second;
    }

    vector<MenuItem> listAll() const {
        vector<MenuItem> out;
        out.reserve(items.size());
        for (const auto& [_, item] : items) out.push_back(item);
        return out;
    }

    vector<MenuItem> listByCategory(const string& category) const {
        vector<MenuItem> out;
        auto it = byCategory.find(category);
        if (it == byCategory.end()) return out;
        for (const auto& name : it->second) {
            auto mit = items.find(name);
            if (mit != items.end()) out.push_back(mit->second);
        }
        return out;
    }

    void printAll() const {
        cout << "=== Full Menu ===\n";
        for (const auto& [cat, names] : byCategory) {
            cout << "\n[" << cat << "]\n";
            for (const auto& name : names) {
                const auto& item = items.at(name);
                printItem(item);
            }
        }
        cout << endl;
    }

    static void printItem(const MenuItem& item) {
        cout << " - " << item.name
             << "  $" << fixed << setprecision(2) << item.price
             << "  — " << item.description << "\n";
    }

    optional<double> priceOf(const string& name) const {
        auto it = items.find(name);
        if (it == items.end()) return nullopt;
        return it->second.price;
    }

private:
    unordered_map<string, MenuItem> items;
    unordered_map<string, vector<string>> byCategory;
};

struct LineItem {
    string name;
    int qty{};
};

struct Bill {
    double subtotal{};
    double tax{};
    double service{};
    double total{};
};

Bill computeBill(const Menu& menu, const vector<LineItem>& order, double taxRate = 0.10, double serviceRate = 0.0) {
    Bill bill{};
    for (const auto& li : order) {
        auto price = menu.priceOf(li.name);
        if (!price) {
            cerr << "[warn] Skipping unknown item: " << li.name << "\n";
            continue;
        }
        bill.subtotal += (*price) * li.qty;
    }
    bill.tax = bill.subtotal * taxRate;
    bill.service = bill.subtotal * serviceRate;
    bill.total = bill.subtotal + bill.tax + bill.service;
    return bill;
}

void printBill(const vector<LineItem>& order, const Menu& menu, const Bill& bill) {
    cout << "\n=== Receipt ===\n";
    for (const auto& li : order) {
        auto price = menu.priceOf(li.name);
        if (!price) continue;
        cout << li.qty << " x " << li.name
             << " @" << fixed << setprecision(2) << *price
             << " = $" << (*price) * li.qty << "\n";
    }
    cout << "Subtotal: $" << bill.subtotal << "\n";
    cout << "Tax:      $" << bill.tax << "\n";
    cout << "Service:  $" << bill.service << "\n";
    cout << "---------------------\n";
    cout << "Total:    $" << bill.total << "\n\n";
}