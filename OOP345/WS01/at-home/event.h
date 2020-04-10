#ifndef SDDS_EVENT_H
#define SDDS_EVENT_H
extern unsigned g_sysClock;
namespace sdds {
	class Event {
		char* des;
		int start = 0;
	public:
		Event();
		Event(const Event& other);
		Event& operator=(const Event& other);
		void display() const;
		void setDescription(char* newDes);
		~Event();
	};
}
#endif // !SDDS_EVENT_H
