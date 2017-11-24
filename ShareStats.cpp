// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

/*	Time begin - 10:17 AM
	Time end -  AM
	Desc: Statistics for share evaluation.
*/

#include "stdafx.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef vector<int> VI;

class Formatter {
public:
	static string left_align_max_20(int number) {
		string s(20, ' ');
		string t = to_string(number);
		return s.replace(s.begin(), s.begin() + t.length(), t);
	}
	static string left_align_max_20(double val) {
		string s(20, ' ');
		string t = to_string(val);
		return s.replace(s.begin(), s.begin() + t.length(), t);
	}
	static string left_align_max_20(string str) {
		string s(20, ' ');
		return s.replace(s.begin(), s.begin() + str.length(), str.substr(0, 20));
	}
};

class ComputedParameters {
public:
	double bvps;
	double bvps_ratio;
	double graham_number;
	double intrinsic_value;
};

class FinancialAlgorithms {
public:
	virtual double compute_bvps(double total_assets, double current_liabilities, double total_shares) {
		return (total_assets - current_liabilities) / total_shares;
	}
	virtual double compute_grahams_number_futuristic(double eps, double bvps, double g) {
		//eps = eps + g / 10;
		return sqrt(22.5 * eps * bvps);
	}
	virtual double compute_intrinsic_value(double eps, double g) {
		//eps = eps + g / 10;
		return eps * (8.5 + 2 * g);
	}
	virtual double compute_bvps_ratio_futuristic(double total_debt, double net_current_assets, double contingent_liabilities, double total_assets) {
		return net_current_assets / total_assets;
	}
};

class FinancialData : FinancialAlgorithms{
public:
	int year;
	int quarter;
	double eps;
	double g; // expected growth rate
	double total_income;
	double total_debt;
	double contingent_liabilities;
	double total_liabilities; // total assets
	double net_current_assets;
	double total_shares;
	ComputedParameters* computed_params = NULL;
	FinancialData(
		int year_a,
		int quarter_a,
		double eps_a, 
		double g_a, 
		double total_income_a,
		double total_deb_a, 
		double contingent_liabilites_a,
		double total_liabilities_a, 
		double net_current_assets_a,
		double total_shares_a):
		year(year_a),
		quarter(quarter_a), 
		eps(eps_a), 
		g(g_a), 
		total_income(total_income_a),
		total_debt(total_deb_a), 
		contingent_liabilities(contingent_liabilites_a),
		total_liabilities(total_liabilities_a), 
		net_current_assets(net_current_assets_a),
		total_shares(total_shares_a)
	{}
	void computeParameters() {
		computed_params = new ComputedParameters();
		computed_params->bvps = compute_bvps(total_liabilities, contingent_liabilities, total_shares);
		computed_params->bvps_ratio = compute_bvps_ratio_futuristic(total_debt, net_current_assets, contingent_liabilities, total_liabilities);
		computed_params->graham_number = compute_grahams_number_futuristic(eps, computed_params->bvps, g);
		computed_params->intrinsic_value = compute_intrinsic_value(eps, g);
	}
};

struct CompareFinancialData {
	bool operator() (FinancialData* fd1, FinancialData* fd2) {
		if (fd1->year > fd2->year) {
			return false;
		}
		else if (fd1->quarter > fd2->quarter) {
			return false;
		}
		return true;
	}
} obj_compare_financial_data;

class ShareData {
public:
	struct tm time;
	double price;
	ShareData(struct tm& t, double price_a) : time(t), price(price_a) {}
};

class CompanyData {
public:
	string company_name;
	vector<FinancialData *> fin_data;
	vector<ShareData *> share_data;
	void print_computed_parameters() {
		for (auto& row : fin_data) {
			cout << Formatter::left_align_max_20(company_name)
				<< Formatter::left_align_max_20(row->year)
				<< Formatter::left_align_max_20(row->quarter)
				<< Formatter::left_align_max_20(row->g)
				<< Formatter::left_align_max_20(row->computed_params->bvps) 
				<< Formatter::left_align_max_20(row->computed_params->bvps_ratio) 
				<< Formatter::left_align_max_20(row->computed_params->graham_number)
				<< Formatter::left_align_max_20(row->computed_params->intrinsic_value) << "\n";
		}
		cout << "\n";
	}
	void compute_growth_rate() {
		const double default_rate = 8;
		sort(fin_data.begin(), fin_data.end(), obj_compare_financial_data);
		for (int i = 1; i < fin_data.size(); ++i) {
			FinancialData* fd_prev = fin_data[i - 1];
			FinancialData* fd_cur = fin_data[i];
			fd_cur->g = (fd_cur->total_income - fd_prev->total_income) * 100 / fd_prev->total_income;
		}
	}
};

class Data {
public:
	vector<CompanyData *> comp_data;
	void print_computed_parameters() {
		cout << Formatter::left_align_max_20("Company")
			<< Formatter::left_align_max_20("Year")
			<< Formatter::left_align_max_20("Quarter")
			<< Formatter::left_align_max_20("Growth Rate")
			<< Formatter::left_align_max_20("Book Value")
			<< Formatter::left_align_max_20("Health Ratio")
			<< Formatter::left_align_max_20("Graham Number")
			<< Formatter::left_align_max_20("Intrinsic Value") << "\n\n";
		for (auto& company : comp_data) {
			company->print_computed_parameters();
		}
	}
};

int main() {
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w+", stdout);
	// Read the data
	// Format is as provided below:
	// Number of companies
	// Company name(without space), Financial data rows, Share Price data rows 
	// year, quarter, eps, g, total_debt, contingent_liabilities, total_assets, net_current_assets, total_shares
	// Date, Share price
	/* Sample Input
	1
	IFB 1 0
	year, quarter, eps, g, total_income, total_debt, contingent_liabilities, total_assets, net_current_assets, total_shares
	11 16 2017 9.8 8 22.23 39.73 475.91 109.81 4.05
	Castrol 1 0
	11 16 2017 3.6 10 0 71.22 596 411.51 49.46
	Pfizer 1 0
	11 16 2017 24.29 15 2.5 498.58 2406 1503 4.57
	SunPharma 1 0
	11 16 2017 2.4 10 4814 6060 25686 1316 240
	*/
	int n;
	cin >> n;
	Data data;
	for (int i = 0; i < n; ++i) {
		CompanyData* company_data = new CompanyData();
		int finRows, shareDataRows;
		cin >> company_data->company_name >> finRows >> shareDataRows;
		for (int j = 0; j < finRows; j++)
		{
			int year, quarter;
			double eps, g, total_income, total_debt, contingent_liabilities, total_liabilities, net_current_assets;
			double total_shares;
			cin >> year >> quarter >> eps >> g >> total_income >> total_debt >> contingent_liabilities >> total_liabilities >> net_current_assets >> total_shares;
			FinancialData* fin_data = new FinancialData(year, quarter, eps, g, total_income, total_debt, contingent_liabilities, total_liabilities, net_current_assets, total_shares);
			fin_data->computeParameters(); // compute the parameters
			company_data->fin_data.push_back(fin_data);
		}
		for (int j = 0; j < shareDataRows; ++j) {
			struct tm time;
			cin >> time.tm_year;
			cin >> time.tm_mon;
			cin >> time.tm_mday;
			int share_price;
			cin >> share_price;
			ShareData* share_data = new ShareData(time, share_price);
			company_data->share_data.push_back(share_data);
		}
		company_data->compute_growth_rate();
		data.comp_data.push_back(company_data);
	}
	data.print_computed_parameters();
}
