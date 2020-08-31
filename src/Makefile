############################################################################3
# Makefile to create spectcl programs for experiments 03034 & 05028
# version 3.0-gcc3.x
# J.Pereira 8/29/2005
############################################################################3
INSTDIR=/usr/opt/spectcl/5.1-004
#INSTDIR=/usr/opt/spectcl/3.4-005
#INSTDIR=/opt/lucid/spectcl/3.3
include $(INSTDIR)/etc/SpecTcl_Makefile.include

#  If you have any switches that need to be added to the default c++ 
# compilation rules, add them to the definition below:

USERCXXFLAGS=$(ROOTCFLAGS) $(ROOTGLIBS) -DHAVE_HLESS_IOSTREAM

#  If you have any switches you need to add to the default c compilation
#  rules, add them to the defintion below:

USERCCFLAGS=$(USERCXXFLAGS) 

#  If you have any switches you need to add to the link add them below:

# USERLDFLAGS= -ltk -ltcl -lSM -lICE
USERLDFLAGS= -lSM -lICE 

#
#   Append your objects to the definitions below:
#

OBJECTS=SpecTcl_ddas.o Unpacker_ddas.o Parameters-ddas.o \
	Variables-ddas.o Calibrator_ddas.o Threshold_ddas.o \
	ddaschannel.o Correlator_ddas.o
#	ddaschannel.o Correlator_ddas_sun.o
#        Correlator_ddas.o Correlator_ddas_sun.o ddaschannel.o  
#
#  Finally the makefile targets.
#

SpecTcl: $(OBJECTS)
	$(CXXLD)  -o ../SpecTcl $(OBJECTS) $(USERLDFLAGS) \
	$(LDFLAGS) 
#	$(CXXLD)  -o ./SpecTcl $(OBJECTS) $(USERLDFLAGS) \
	$(LDFLAGS) 


clean:
	rm -f $(OBJECTS) ../SpecTcl
#	rm -f $(OBJECTS) ./SpecTcl

depend:
	makedepend $(USERCXXFLAGS) *.cpp *.c

help:
	echo "make                 - Build customized SpecTcl"
	echo "make clean           - Remove objects from previous builds"
	echo "make depend          - Add dependencies to the Makefile. "
