#include "s15c_account_util.hpp"

namespace udemy1::s15c
{
using std::cout, std::endl;

/**
 * @brief Display Account objects in a vector of Account object
 * @param account
 */
void display(const std::vector<Account>& account)
{
    cout << "\n=== Accounts ==========================================================" << endl;
    for (const auto& acc : account)
        cout << acc << endl;
}

/**
 * @brief Display Savings Account objects in a vector of Savings_Account object
 * @param account
 */
void display(const std::vector<Savings_Account>& account)
{
    cout << "\n=== Savings Accounts ==================================================" << endl;
    for (const auto& acc : account)
        cout << acc << endl;
}

/**
 * @brief Display Checking Account objects in a vector of Checking_Account object
 * @param account
 */
void display(const std::vector<Checking_Account>& account)
{
    cout << "\n=== Checking Accounts =================================================" << endl;
    for (const auto& acc : account)
        cout << acc << endl;
}

/**
 * @brief Display Trust Account objects in a vector of Trust_Account object
 * @param account
 */
void display(const std::vector<Trust_Account>& account)
{
    cout << "\n=== Trust Accounts ====================================================" << endl;
    for (const auto& acc : account)
        cout << acc << endl;
}

/**
 * @brief Deposit supplied amount to Account objects in a vector
 * @param account
 * @param amt
 */
void deposit(std::vector<Account>& account, double amt)
{
    cout << "\n=== Depositing to Accounts ============================================" << endl;
    for (auto& acc : account) {
        if (acc.deposit(amt))
            cout << "Deposited " << amt << " to " << acc << endl;
        else
            cout << "Failed Deposit of " << amt << " to " << acc << endl;
    }
}

/**
 * @brief Deposit supplied amount to Savings_Account objects in a vector
 * @param account
 * @param amt
 */
void deposit(std::vector<Savings_Account>& account, double amt)
{
    cout << "\n=== Depositing to Savings Accounts ====================================" << endl;
    for (auto& acc : account) {
        if (acc.deposit(amt))
            cout << "Deposited " << amt << " to " << acc << endl;
        else
            cout << "Failed Deposit of " << amt << " to " << acc << endl;
    }
}

/**
 * @brief Deposit supplied amount to Checking_Account objects in a vector
 * @param account
 * @param amt
 */
void deposit(std::vector<Checking_Account>& account, double amt)
{
    cout << "\n=== Depositing to Checking Accounts ===================================" << endl;
    for (auto& acc : account) {
        if (acc.deposit(amt))
            cout << "Deposited " << amt << " to " << acc << endl;
        else
            cout << "Failed Deposit of " << amt << " to " << acc << endl;
    }
}

/**
 * @brief Deposit supplied amount to Trust_Account objects in a vector
 * @param account
 * @param amt
 */
void deposit(std::vector<Trust_Account>& account, double amt)
{
    cout << "\n=== Depositing to Trust Accounts ======================================" << endl;
    for (auto& acc : account) {
        if (acc.deposit(amt))
            cout << "Deposited " << amt << " to " << acc << endl;
        else
            cout << "Failed Deposit of " << amt << " to " << acc << endl;
    }
}

/**
 * @brief Withdraw amount from each Account objects in a vector
 * @param account
 * @param amt
 */
void withdraw(std::vector<Account>& account, double amt)
{
    cout << "\n=== Withdrawing from Accounts =========================================" << endl;
    for (auto& acc : account) {
        if (acc.withdraw(amt))
            cout << "Withdrew " << amt << " from " << acc << endl;
        else
            cout << "Failed Withdrawal of " << amt << " from " << acc << endl;
    }
}

/**
 * @brief Withdraw amount from each Savings_Account objects in a vector
 * @param account
 * @param amt
 */
void withdraw(std::vector<Savings_Account>& account, double amt)
{
    cout << "\n=== Withdrawing from Savings Accounts =================================" << endl;
    for (auto& acc : account) {
        if (acc.withdraw(amt))
            cout << "Withdrew " << amt << " from " << acc << endl;
        else
            cout << "Failed Withdrawal of " << amt << " from " << acc << endl;
    }
}

/**
 * @brief Withdraw amount from each Checking_Account objects in a vector
 * @param account
 * @param amt
 */
void withdraw(std::vector<Checking_Account>& account, double amt)
{
    cout << "\n=== Withdrawing from Checking Accounts ================================" << endl;
    for (auto& acc : account) {
        if (acc.withdraw(amt))
            cout << "Withdrew " << amt << " from " << acc << endl;
        else
            cout << "Failed Withdrawal of " << amt << " from " << acc << endl;
    }
}

/**
 * @brief Withdraw amount from each Trust_Account objects in a vector
 * @param account
 * @param amt
 */
void withdraw(std::vector<Trust_Account>& account, double amt)
{
    cout << "\n=== Withdrawing from Trust Accounts ===================================" << endl;
    for (auto& acc : account) {
        if (acc.withdraw(amt))
            cout << "Withdrew " << amt << " from " << acc << endl;
        else
            cout << "Failed Withdrawal of " << amt << " from " << acc << endl;
    }
}

} // namespace udemy1::s15c
