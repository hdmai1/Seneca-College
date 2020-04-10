// Name: Huu Duc Mai
// Seneca Student ID: 121367189
// Seneca email: hdmai1@myseneca.ca
// Date of completion: Feb 18, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <iostream>
#include <string>
namespace sdds {
   template <typename T>
   class Collection {
      std::string m_name;
      T* m_items;
      size_t m_size;
      void (*m_obs)(const Collection<T>& C1, const T&) {};
   public:
      Collection(std::string name) {
         m_name = name;
         m_items = nullptr;
         m_size = 0;
         m_obs = nullptr;
      }
      Collection(const Collection<T>&) = delete;
      ~Collection() { delete[] m_items; };
      const std::string& name() const { return m_name; }
      size_t size() const { return m_size; };
      void setObserver(void (*observer) (const Collection<T>& C1, const T& newC)) {
         m_obs = observer;
      };
      Collection<T>& operator+=(const T& item) {
         bool truefalse{};
         for (size_t i = 0u; i < m_size && m_items != nullptr; i++) {
            if (m_items[i].title() == item.title()) {
               truefalse = true;
               break;
            }
         }
         if (!truefalse) {
            m_size++;
            T* temp = new T[m_size];
            for (size_t i = 0u; i < m_size - 1u; i++)
               temp[i] = m_items[i];
            delete[] m_items;
            temp[m_size - 1u] = item;
            m_items = temp;
            if (m_obs != nullptr)
               m_obs(*this, item);
         }
         return *this;
      };
      T& operator[](size_t idx)const {
         std::string str = "Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(size()) + "] items.";
         if (idx >= m_size)
            throw std::out_of_range(str);
         else
            return m_items[idx];
      };
      T* operator[](std::string title)const {
         bool truefalse{};
         size_t index{};
         for (size_t i = 0; i < m_size; i++) {
            if (m_items[i].title() == title) {
               truefalse = true;
               index = i;
               break;
            }
         }
         return truefalse ? &m_items[index] : nullptr;
      };
      
   };
   template<typename T>
   std::ostream& operator<<(std::ostream& os, const Collection<T>& C1) {
      for (size_t i = 0; i < C1.size(); i++) {
         os << C1[i];
      }
      return os;
   };
}
#endif // !SDDS_COLLECTION_H
