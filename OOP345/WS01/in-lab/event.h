#ifndef SDDS_EVENT_H
#define SDDS_EVENT_H
extern unsigned g_sysClock;
namespace sdds {
	class Event {
		char des[129];
		int start;
	public:
		Event();
		void display() const;
		void setDescription(char* newDes);
	};
}
#endif // !SDDS_EVENT_H
