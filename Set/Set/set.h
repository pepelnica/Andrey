#include <iostream>
#include <vector>
class Set {
 private:
  std::vector<int64_t> massive_;

 public:
  explicit Set() {}
  explicit Set(const std::vector<int64_t> set_) {
    for (int i = 0; i < set_.size(); i++) {
      Add(set_[i]);
    }
  }

  void Add(int64_t value_) {
    if (!Contains(value_)) {
      massive_.push_back(value_);
    }
  }

  bool Contains(int64_t value_) {
    for (int i = 0; i < massive_.size(); i++) {
      if (value_ == massive_[i]) {
        return true;
      } else {
        return false;
      }
    }
  }

  void Remove(int64_t delete_value) {
    for (int i = 0; i < massive_.size(); i++) {
      if (massive_[i] == delete_value) {
        massive_.erase(massive_.begin() + i);
      }
    }
  }

  auto Data() { return massive_; }

  Set Union(const Set& value) {
    Set copy = value;
    std::vector<int64_t> come_vec = copy.Data();
    Set constr_vec(massive_);
    for (int i = 0; i < come_vec.size(); i++) {
      constr_vec.Add(come_vec[i]);
    }
    return constr_vec;
  }

  Set Intersection(const Set& value) {
    Set razn;
    std::vector<int64_t> constr_vec = massive_;
    Set copy = value;
    std::vector<int64_t> come_vec = copy.Data();
    for (int i = 0; i < constr_vec.size(); i++) {
      for (int j = 0; j < come_vec.size(); j++) {
        if (constr_vec[i] == come_vec[j]) {
          razn.Add(constr_vec[i]);
        }
      }
    }
    return razn;
  }

  Set Difference(const Set& value) {
    Set copy = value;
    std::vector<int64_t> come_vec = copy.Data();
    Set constr_vec(massive_);
    for (int i = 0; i < massive_.size(); i++) {
      for (int j = 0; j < come_vec.size(); j++) {
        if (massive_[i] == come_vec[j]) {
          constr_vec.Remove(come_vec[i]);
        }
      }
    }
    return constr_vec;
  }

  Set SymmetricDifference(const Set& value) {
    Set copy = value;
    std::vector<int64_t> come_vec = copy.Data();
    Set constr_vec(massive_);
    for (int i = 0; i < massive_.size(); i++) {
      for (int j = 0; j < come_vec.size(); j++) {
        if (massive_[i] == come_vec[j]) {
          constr_vec.Remove(massive_[i]);
          copy.Remove(massive_[i]);
        }
      }
    }
    constr_vec.Union(copy);
    return constr_vec;
  }
};
