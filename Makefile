#
# Names: Javely Benitez, Troy Edwards, Ashley Kaur, Anjie Obasunloye, Joy Zhu
# Emails: jtejedabenitez@scu.edu, tedwards2@scu.edu, akaur3@scu.edu, aobasunloye@scu.edu, jhzhu@scu.edu
# For CSEN79 HW1 Rational Number
# 
TMPMAKE=tmpMake
STD=-std=c++20
OPT=-g
CXXFLAGS=${STD} ${OPT}

%.o: %.cxx
	$(CXX) -c $(CXXFLAGS) $<

%: %.cxx
	$(CXX) -o $@ $(CXXFLAGS) $<

SRCS=ratnum.cxx ratnummain.cxx 
OBJS=$(SRCS:.cxx=.o)
ALL=ratnum

all: $(ALL)

ratnum: $(OBJS)
	$(CXX) -o $@ $(CXXFLAGS) $+

clean:
	/bin/rm -f $(OBJS) $(ALL) testdata.txt
	/bin/rm -rf $(ALL:=.dSYM)

depend: $(SRCS)
	TMP=`mktemp -p .`; export TMP; \
	sed -e '/^# DEPENDENTS/,$$d' Makefile > $$TMP; \
	echo '# DEPENDENTS' >> $$TMP; \
	$(CXX) -MM $+ >> $$TMP; \
	/bin/mv -f $$TMP Makefile

# DEPENDENTS
ratnum.o: ratnum.cxx ratnum.h
ratnummain.o: ratnummain.cxx ratnum.h
