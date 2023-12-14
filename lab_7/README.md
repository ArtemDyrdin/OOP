# Лабораторная работа №7
1. __Создайте шаблон интерфейса IRepository<T>:__

   void Add(T* item) \
   void Update(T* item) \
   void Delete(T* item) \
   std::vector<T*> Get(const std::string&where, const std::string&
   OrderBy)


2. __Создайте класс User:__

    int mld \
    std::string mName \
    std::string mEmail \
    std::string mPhone \
    std::string mCity \
    Пол (мужской, женский) mGender \
    Добавить функции геттеры и сеттеры


3. __Создайте интерфейс UserRepository : public IRepository<Пользователь>:__

    T* getByld(int id) \
    T* getByName(const std::строка и имя) \
    T* getByEmail(const std::строка и адрес электронной почты) \
    std: :vector<T*> getByCity(const std::string&
    city) \
    std::vector<T*> getByGender(Пол, гендер)


4. __Создайте класс MemoryRepository<T> : public IRepository<T>__, \
   реализующий работу с объектами в оперативной
   памяти.


5. __Создайте класс MemoryUserRepository : public MemoryRepository<T>, общедоступный
    IUserRepository__, \
    реализующий работу с пользовательскими объектами в
    оперативной памяти.


6. Продемонстрируйте работу приложения, __добавляя__,
   __изменяя__, __удаляя__ и __извлекая__ пользовательские объекты из хранилища
   _MemoryUserRepository_.