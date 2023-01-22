#pragma once
#include <map>
#include <iostream>
#include <vector>
#include<unordered_map>


template<class T>
class Database
{
public:
	Database() : _idKey(0){}

	T getDataMap() {
		return _dataMap;
	}

	void setDataMap(T dataMap) {
		_dataMap = dataMap;
	}

	void addData(T data) {
		_idKey++;
		const auto& [it, isInserted] = _dataMap.insert({ _idKey, data });
		if (!isInserted) {
			std::cout << "Error of adding data" << std::endl;
		}
	}
	void showData() {
		for (const auto& [key, value] : _dataMap) {
			std::cout << key << " " << value << std::endl;
		}
	}
	void modifyData(int num, T data) {
		for (const auto& [key, value] : _dataMap) {
			if (num == key) {
				_dataMap.erase(num);
				_dataMap.emplace(num, data);
			}
			else
			
			{
				std::cout << "Modification Error." << std::endl;
			}
		}
	}

	void searchData(int num) {
		for (const auto& [key, value] : _dataMap) {
			if (num == key) {
				std::cout << "We searched: " << key << " " << value << std::endl;
				_mostSearhed.push_back(key);
			}
		}
	}



	void deleteData(int num) {
		
				auto it = _dataMap.find(num);
				_dataMap.erase(num);
			
	}

	int mostSearchedKey() {
		std::unordered_map<int, int> keyAmount;
		for (size_t i = 0; i < _mostSearhed.size(); i++) {
			const auto& [it, isInserted] = keyAmount.insert({
			   _mostSearhed[i], 1 });
			if (!isInserted) {
				int value = it->second;
				value++;
				keyAmount[_mostSearhed[i]] = value;
			}
		}
		std::pair<int, int> key_biggestValue = { 0,0 };
		for (std::unordered_map<int, int>::const_iterator it =
			keyAmount.begin();
			it != keyAmount.end(); it++) {
			if (key_biggestValue.second < it->second) {
				key_biggestValue = std::make_pair(it->first,
					it->second);
			}
		}
		return key_biggestValue.first;
	}



private:

	std::map<int, T> _dataMap;
	int _idKey;
	T _data;
	std::vector<int> _mostSearhed;

};

	