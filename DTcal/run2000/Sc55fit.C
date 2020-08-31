//#include "TFile.h";
#include "TH1F.h";
#include <iostream>;
//#include "TArray.h";
//#include "CallFunc.h";
//#include "TMinuit.h";
using namespace std;
//Double_t bateman(Double_t *x, Double_t *par)

double binn = 1; //1 bin / binning ms 
double histostart = 0;
double histoend = 996E6;
//double totbins = (histoend-histostart)/(1000000*binn);
double totbins = 996;
double daughterl = 0.693/(130/binn);
double ndaughterl = 0.693/(210/binn);

double gdaughterl = 0.693/(2100000000/binn);
double ngdaughterl = 0.693/(7000000000/binn);

Double_t errorc[1000];
Double_t stuffs[1000];
Double_t targlist[10];
Double_t binno[1000];

//bin = 1;
//static const bins;
//Functions

//Double_t bateman(double t,Double_t *targlist);

//void Cint::G__CallFunc::SetArgArray(long* p, int narg=-1);

Double_t bateman(double x, Double_t *par)
   {
   
      Double_t C1, dC1, dC2, ndC1, ndC2, N;
      Double_t dC1n, dndC1, dC2n, dndC2;
      Double_t gdC1, gdC2, gdC3;
      Double_t ngdC1, ngdC2, ngdC3;

      //Bateman equation for parent
      C1 = par[1];                                       /* Initial parent activity */
   
      //Bateman equations for daughter
      dC1 = daughterl*par[1]/((daughterl-par[0]));
      dC2 = daughterl*par[1]/((par[0]-daughterl));
   
      //Bateman equation for neutron daughter
      ndC1 = ndaughterl*par[1]/((ndaughterl-par[0]));
      ndC2 = ndaughterl*par[1]/((par[0]-ndaughterl));
   
      //Bateman equation for grand-daughter
      gdC1 = gdaughterl*daughterl*par[1]/((daughterl-par[0])*(gdaughterl-par[0]));
      gdC2 = gdaughterl*daughterl*par[1]/((par[0]-daughterl)*(gdaughterl-daughterl));
      gdC3 = gdaughterl*daughterl*par[1]/((par[0]-gdaughterl)*(daughterl-gdaughterl));
      
      //Bateman equation for neutron grand-daughter
      ngdC1 = ndaughterl*ngdaughterl*par[1]/((ndaughterl-par[0])*(ngdaughterl-par[0]));
      ngdC2 = ndaughterl*ngdaughterl*par[1]/((par[0]-ndaughterl)*(ngdaughterl-ndaughterl));
      ngdC3 = ndaughterl*ngdaughterl*par[1]/((par[0]-ngdaughterl)*(ndaughterl-ngdaughterl));



      N = C1*(TMath::Exp(-par[0]*x)) //Parent activity 
           + (1-par[3])*(dC1*TMath::Exp(-par[0]*x) + dC2*TMath::Exp(-daughterl*x)) //Daughter 
           + (par[3])*(ndC1*TMath::Exp(-par[0]*x) + ndC2*TMath::Exp(-ndaughterl*x)) //nDaughter
           + (1-par[3])*(gdC1*TMath::Exp(-par[0]*x)+ gdC2*TMath::Exp(-daughterl*x) + gdC3*TMath::Exp(-gdaughterl*x)) //Granddaughter
           + (par[3])*(ngdC1*TMath::Exp(-par[0]*x)+ ngdC2*TMath::Exp(-ndaughterl*x) + ngdC3*TMath::Exp(-ngdaughterl*x))
           + par[2]*TMath::Exp(-par[4]*x[0]);
   
     /* par[0] = parent half-life
        par[1] = initial parent activity
        par[2] = background
        par[3] = Pn in
        par[4] = bg half-life*/
   
     Double_t value = N;
     return value;
   
   }

static Double_t fcn(Int_t &npar, Double_t *gin, Double_t &f, Double_t *par, Int_t iflag)   /* This calculates Xi square */
{

   Int_t i;

   //calculate chisquare
   Double_t chisq = 0;
   Double_t delta;
   //for (i=histostart/1000000;i<histoend/1000000;i++) {
   for (i=0;i<totbins+1;i++) {
     binno[i] = i+0.5;
     if(errorc[i] >0) 
       {
         delta = (stuffs[i]-bateman(binno[i],par))/errorc[i] /*(TMath::Sqrt(func(i+(bin/2),par)))*/ ;    
         //cout << delta << endl;
          //cout << bateman(binno,par) << endl;
       }
     else delta = 0;
     chisq += delta*delta;
     }
   f = chisq;
   if ((chisq)<973){
     ofstream expf;
     expf.open("pars.dat", std::ios_base::app);
     for(int k=0; k<5;k++){
       expf << par[k] << " ";
     }
     expf << "\n";
   }
   //cout << f << endl;
   Double_t red = chisq/(totbins - 5);
   //ofstream outpfile("tst.txt", ofstream::out | ofstream::app);
   //outpfile << red << "\n";
   //outfile.close();
   return f;
  //f = bateman->GetChisquare();
}


Double_t parent(Double_t *x, Double_t *par){
   Double_t parentval = par[0]*TMath::Exp(-par[1]*x[0]);
   /*par[0] : Parent initial activity
     par[1] : Parent half-life */
   return parentval;
}


Double_t daughter(Double_t *x, Double_t *par){
   Double_t daughterval = par[0]*TMath::Exp(-par[2]*x[0]) + par[1]*TMath::Exp(-daughterl*x[0]); 
   /*par[0] : dC1
     par[1] : dC2
     par[2] : parent half-life*/
   return daughterval;  
}

Double_t ndaughter(Double_t *x, Double_t *par){
   Double_t ndaughterval = par[0]*TMath::Exp(-par[2]*x[0]) + par[1]*TMath::Exp(-ndaughterl*x[0]); 
   /*par[0] : dC1
     par[1] : dC2
     par[2] : parent half-life*/
   return ndaughterval;  
}

Double_t granddaughter(Double_t *x, Double_t *par)
{
  Double_t C1, dC1, dC2, gdC1,gdC2,gdC3, ngdC1, ngdC2, ngdC3, N;
 
  //Bateman equations for granddaughter
  /*gdC1 = daughterl*gdaughterl/((daughterl-par[0])*(gdaughterl-par[0]))*par[1];
  gdC2 = daughterl*gdaughterl/((par[0]-daughterl)*(gdaughterl-daughterl))*par[1];
  gdC3 = daughterl*gdaughterl/((par[0]-gdaughterl)*(daughterl-gdaughterl))*par[1];*/
  N = par[0]*TMath::Exp(-par[3]*x[0])+ par[1]*TMath::Exp(-daughterl*x[0]) + par[2]*TMath::Exp(-gdaughterl*x[0]);
  //cout << gdC1 << " --- " << gdC2 << " --- " << gdC3 << " --- " << endl;
  Double_t granddvalue = N;
  return granddvalue;
}

Double_t ngranddaughter(Double_t *x, Double_t *par)
{
  Double_t C1, dC1, dC2, gdC1,gdC2,gdC3, N;
  //Bateman equations for granddaughter
  /*gdC1 = ndaughterl*ndaughterl/((ndaughterl-par[0])*(ndaughterl-par[0]))*par[1];
0 591
  gdC2 = ndaughterl*ndaughterl/((par[0]-ndaughterl)*(ndaughterl-ndaughterl))*par[1];
  gdC3 = ndaughterl*ndaughterl/((par[0]-ndaughterl)*(ndaughterl-ndaughterl))*par[1];*/
  N = par[0]*TMath::Exp(-par[3]*x[0])+ par[1]*TMath::Exp(-ndaughterl*x[0]) + par[2]*TMath::Exp(-ngdaughterl*x[0]);
  //cout << gdC1 << " --- " << gdC2 << " --- " << gdC3 << " --- " << endl;
  Double_t granddvalue = N;
  return granddvalue;
}

Double_t background(Double_t *x, Double_t *par){
   Double_t bg = par[0]*TMath::Exp(-par[1]*x[0]);
   return bg;
}


void fitcorr(char* inputfile, char* outputfile){
   //Get inputfile
   //ofstream outfile; 
   //outfile.open("test.txt");
   //TFile *fIn = TFile::Open(inputfile);
   
   //Get histogram
   //t->Draw("correlation_implant_decay_time>>hcorr(1000,0,1000000000)");
   //ft->Draw(Form("correlation_implant_decay_time>>hcorr(%i,%i,%i)",int(totbins),int(histostart),int(histoend)));
   //t->Draw("correlation_implant_decay_time>>hcorr(1000,0,1000000000)","td_NERO_raw>0");
   TH1F* histo = new TH1F("fit","fit",totbins,0,996);
   ifstream in;
   in.open(inputfile);
   Float_t abc, hvals;
   Int_t nlines = 0;
   
   while(!in.eof()){
     in >> abc >> hvals;
     histo->SetBinContent(abc,hvals);
     cout << abc << hvals << endl;
     nlines++;
   }
   //TH1F *histo = (TH1F*)hcorr->Clone("histo");
   histo->Draw();
   int rebfac = 10;
   histo->Rebin(rebfac);
   totbins = totbins/rebfac;
   //break;
   //Fill the array from the histogram
   for(int i = 0; i < totbins+1; i++){
     //for(int j = 0; j <binn;j++){
     //cout << "i = " << i << " ";
     //cout << histo->GetBinContent(i);
     stuffs[i] = histo->GetBinContent(i);
     //cout << " Stuffs at " << i << " is " << stuffs[i];
     //errorc[i] = histo->GetBinError(i*10+j);
     //cout << " and Errorc is " << errorc[i] << endl;
     //}
     errorc[i] = histo->GetBinError(i);
     //cout << " and Errorc is " << errorc[i] << endl;
   }
   //Run Minuit
   TMinuit *gMinuit = new TMinuit(5); //TMinuit(number of params) 
   gMinuit->SetFCN(fcn);         //fcn is the function to minimise, in this case chisq   
   
   Double_t arglist[10];
   Int_t ierflg = 0;
   arglist[0] = 1;
   gMinuit->mnexcm("SET ERR", arglist ,1,ierflg);
   
   cout << "aftermnexcm" << endl;
  /* param[0]: lambda_parent in ms
     param[1]: parent initial activity 
     param[2]: Background initial activity
     param[3]: Pn of parent 
     param[4]: Background decay const */
   
   Double_t vstart[5] = {0.693/100.00,100.0,30.0,0.10,0.693/10000000000};   //start param
   Double_t step[5] = {.000001,1,0.01,.01,0.0000000001};        // Step size used to minimize the parameters
  
  /* Set the fit variables to their initial states from above */

  /*gMinuit->mnparm(par no., parname, starting guess, step size, 
    limit low, limit upper,command (ierflg=0 if mnparm is successful) */
  
  //Parent half-life, param[0]
  //gMinuit->mnparm(0, "parent half-life", vstart[0], step[0],0.693/100,0.693/1.0,ierflg);
  gMinuit->mnparm(0, "parent half-life", vstart[0], step[0],0.693/(200/binn),0.693/(1/binn),ierflg);
  //gMinuit->mnparm(0, "parent half-life", vstart[0], step[0],0.693/(50/binn),0.693/(48/binn),ierflg);
   cout <<"after parent" << endl;
  //Initial parent activity, param[1]
   gMinuit->mnparm(1, "N0" , vstart[1], step[1], 1*binn,15000*binn,ierflg);
  
  //Background, param[2]
   gMinuit->mnparm(2, "Cbackground", vstart[2], step[2], 0*binn, 5000*binn, ierflg); 


  //Pn, param[3]
   gMinuit->mnparm(3, "Pn", vstart[3], step[3],0.0,0.17,ierflg);
   
  //Background decay const, param[4]
   gMinuit->mnparm(4, "Lbackground", vstart[4], step[4],0,0.693/100000000,ierflg); 
   
   cout << "Managed to Set Params" << endl; 
  
  // Now ready for minimization step
   arglist[0] = 10000;
   arglist[1] = 0.01;
   cout << "fin" << endl;

   //Run MIGRAD
   gMinuit->mnexcm("MIGRAD", arglist,2,ierflg); 
   cout << "Migrad ran" << endl;
   Double_t amin, edm, errdef;
   Int_t nvpar, nparx,icstat;
   gMinuit->mnstat(amin,edm,errdef,nvpar,nparx,icstat);
   gMinuit->mnprin(3,amin);


   //Get the minimised parameters
   Double_t ParentT[2];
   gMinuit->GetParameter(0,ParentT[0],ParentT[1]);
   cout << "Set the parent" << endl;
 
   Double_t N0[2];
   gMinuit->GetParameter(1,N0[0],N0[1]);
   cout << "Set the init activity" << endl;
   
   Double_t Background[2];
   gMinuit->GetParameter(2,Background[0],Background[1]);
   cout << "Set the background" << endl;
   
   Double_t Pn[2];
   gMinuit->GetParameter(3,Pn[0],Pn[1]);
   cout << "Set the Pn" << endl;
  
   Double_t LBackground[2];
   gMinuit->GetParameter(4,LBackground[0],LBackground[1]);
   cout << "Set the background decay const" << endl;
   
   Double_t xlim[2];
   xlim[0] = 0;
   xlim[1] = totbins;
   
   
   //Get the co-efficients
   double dC1 = (1-Pn[0])*daughterl*N0[0]/((daughterl-ParentT[0]));
   double dC2 = (1-Pn[0])*daughterl*N0[0]/((ParentT[0]-daughterl));

   double ndC1 = Pn[0]*ndaughterl*N0[0]/(ndaughterl-ParentT[0]);
   double ndC2 = Pn[0]*ndaughterl*N0[0]/(ParentT[0]-ndaughterl);

   double gdC1 = (1-Pn[0])*gdaughterl*daughterl*N0[0]/((daughterl-ParentT[0])*(gdaughterl-ParentT[0]));
   double gdC2 = (1-Pn[0])*gdaughterl*daughterl*N0[0]/((ParentT[0]-daughterl)*(gdaughterl-daughterl));
   double gdC3 = (1-Pn[0])*gdaughterl*daughterl*N0[0]/((ParentT[0]-gdaughterl)*(daughterl-gdaughterl));

   double ngdC1 = Pn[0]*gdaughterl*ndaughterl*N0[0]/((ndaughterl- ParentT[0])*(ngdaughterl-ParentT[0]));
   double ngdC2 = Pn[0]*gdaughterl*ndaughterl*N0[0]/((ParentT[0]-ndaughterl)*(ngdaughterl-ndaughterl));
   double ngdC3 = Pn[0]*gdaughterl*ndaughterl*N0[0]/((ParentT[0]-ngdaughterl)*(ndaughterl-ngdaughterl));


   // Make the functions
   TF1 *dparent = new TF1("V-61", parent,xlim[0],xlim[1],2);
   dparent->SetParameter(0,N0[0]);
   dparent->SetParameter(1,ParentT[0]);
   dparent->SetParNames("N0","ParentT");
   cout << "Hello" << dparent->Integral(1,25) << endl;
   
   TF1 *daughter = new TF1("Cr-61", daughter,xlim[0],xlim[1],3);
   daughter->SetParameter(0,dC1);
   daughter->SetParameter(1,dC2);
   daughter->SetParameter(2,ParentT[0]);
   cout << "Hello" << daughter->Integral(1,25) << endl;
   cout << "Hello" << daughter->Integral(30,40.49) << endl;
   
   TF1 *ndaughter = new TF1("Cr-60", ndaughter,xlim[0],xlim[1],3);
   ndaughter->SetParameter(0,ndC1);
   ndaughter->SetParameter(1,ndC2);
   ndaughter->SetParameter(2,ParentT[0]);
   cout << "Hello" << ndaughter->Integral(1,25) << endl;
   cout << "Hello" << ndaughter->Integral(30,40.49) << endl;
   
   TF1 *granddaughter = new TF1("Mn-61", granddaughter,xlim[0],xlim[1],4);
   granddaughter->SetParameter(0,gdC1);
   granddaughter->SetParameter(1,gdC2);
   granddaughter->SetParameter(2,gdC3);
   granddaughter->SetParameter(3,ParentT[0]);
   cout << "Hello" << granddaughter->Integral(1,25) << endl;
   
   TF1 *ngranddaughter = new TF1("Mn-60", ngranddaughter,xlim[0],xlim[1],4);
   ngranddaughter->SetParameter(0,ngdC1);
   ngranddaughter->SetParameter(1,ngdC2);
   ngranddaughter->SetParameter(2,ngdC3);
   ngranddaughter->SetParameter(3,ParentT[0]);
   cout << "Hello" << ngranddaughter->Integral(1,25) << endl;

   TF1 *background = new TF1("background",background,xlim[0],xlim[1],2);
   background->SetParameter(0,Background[0]);
   background->SetParameter(1,LBackground[0]);
   
     //Define total bateman function
   Double_t total(Double_t *x, Double_t *par)
   {
   
      Double_t C1, dC1, dC2, ndC1, ndC2, N;
      Double_t dC1n, dndC1, dC2n, dndC2;
      Double_t gdC1, gdC2, gdC3;
      Double_t ngdC1, ngdC2, ngdC3;
      
      //Bateman equation for parent
      C1 = par[1];                                       /* Initial parent activity */
   
      //Bateman equations for daughter
      dC1 = daughterl*par[1]/((daughterl-par[0]));
      dC2 = daughterl*par[1]/((par[0]-daughterl));
   
      //Bateman equation for neutron daughter
      ndC1 = ndaughterl*par[1]/((ndaughterl-par[0]));
      ndC2 = ndaughterl*par[1]/((par[0]-ndaughterl));

     //Bateman equations for granddaughter
     gdC1 = par[1]*gdaughterl*daughterl/((daughterl-par[0])*(gdaughterl-par[0]));
     gdC2 = par[1]*gdaughterl*daughterl/((par[0]-daughterl)*(gdaughterl-daughterl));
     gdC3 = par[1]*gdaughterl*daughterl/((par[0]-gdaughterl)*(daughterl-gdaughterl));

     //Bateman equations for ngd
     ngdC1 = par[1]*ngdaughterl*ndaughterl/((ndaughterl-par[0])*(ngdaughterl-par[0]));
     ngdC2 = par[1]*ngdaughterl*ndaughterl/((par[0]-ndaughterl)*(ngdaughterl-ndaughterl));
     ngdC3 = par[1]*ngdaughterl*ndaughterl/((par[0]-ngdaughterl)*(ndaughterl-ngdaughterl));

      N = C1*(TMath::Exp(-par[0]*x[0])) + (1-par[3])*(dC1*TMath::Exp(-par[0]*x[0]) + dC2*TMath::Exp(-daughterl*x[0])) + (par[3])*(ndC1*TMath::Exp(-par[0]*x[0]) + ndC2*TMath::Exp(-ndaughterl*x[0]))+ (1-par[3])*(gdC1*TMath::Exp(-par[0]*x[0])+ gdC2*TMath::Exp(-daughterl*x[0]) + gdC3*TMath::Exp(-gdaughterl*x[0])) + par[3]*(ngdC1*TMath::Exp(-par[0]*x[0])+ ngdC2*TMath::Exp(-ndaughterl*x[0]) + ngdC3*TMath::Exp(-ngdaughterl*x[0])) + par[2]*TMath::Exp(-par[4]*x[0]);
   
     /* par[0] = parent half-life
        par[1] = initial parent activity
        par[2] = background
        par[3] = Pn 
        par[4] = background decay const
     */
   
     Double_t value = N;
     return value;
   
   }


   TF1 *totalrate = new TF1("Total decay curve",total,xlim[0],xlim[1],5);
   totalrate->SetTitle("Total Decay Curve");
   totalrate->SetParameter(0,ParentT[0]);
   totalrate->SetParameter(1,N0[0]);
   totalrate->SetParameter(2,Background[0]);
   totalrate->SetParameter(3,Pn[0]);
   totalrate->SetParameter(4,LBackground[0]);
   cout << "Hello" << totalrate->Integral(1,25) << endl;
   
   // Format the plot
   //TCanvas *c1 = new TCanvas();
   
   int yaxisend = histo->GetMaximum()*1.1; 
   dparent->GetYaxis()->SetRangeUser(0,yaxisend);
   dparent->SetTitle("V-61");
   /*xax = dparent->GetXaxis();
   xax->SetBit(TAxis::kLabelsHori);
   xax->SetBinLabel(xax->FindBin("0"),"0");
   xax->SetBinLabel(12,"50");
   xax->SetBinLabel(24,"100");
   xax->SetBinLabel(36,"150");
   xax->SetBinLabel(48,"200");
   xax->SetBinLabel(60,"250");
   xax->SetBinLabel(72,"300");
   xax->SetBinLabel(84,"350");
   xax->SetBinLabel(96,"400");
   xax->SetLabelSize(0.05);*/
   dparent->Draw();
   
   daughter->SetLineColor(4);
   daughter->Draw("same");
   daughter->SetTitle("Cr-61");
 
   ndaughter->SetLineColor(7);
   ndaughter->Draw("same");
   ndaughter->SetTitle("Cr-60");
   
   granddaughter->SetLineColor(4);
   granddaughter->SetLineStyle(2);
   granddaughter->Draw("same");
   granddaughter->SetTitle("Mn-61");
   
   ngranddaughter->SetLineColor(7);
   ngranddaughter->SetLineStyle(2);
   ngranddaughter->Draw("same");
   ngranddaughter->SetTitle("Mn-60");
   
   background->SetLineColor(3);
   background->Draw("same");
   background->SetTitle("Background");
   
   totalrate->SetLineWidth(4);
   //totalrate->Draw("same");
   
   TH1F *decaycurve = new TH1F("Data","Data",totbins,0,totbins);
   int content = 0;

   TText *labe = new TText(int(totbins/10),yaxisend+10,(Form("Decay Curve (binning factor %i, up to %i ms)", int(binn),int(histoend/1E6))));
   labe->Draw();
   for (int i=0; i<totbins+1; i++){
     content = histo->GetBinContent(i);
     decaycurve->SetBinContent(i,content);
   }
   TH1F *dc = (TH1F*)decaycurve->Clone("dc");
   //dc->Draw("same");
   decaycurve->GetYaxis()->SetRangeUser(0,yaxisend);
   decaycurve->Draw("E,same");  
   labe->Draw();
   totalrate->Draw("same");
   c1->BuildLegend();
   //c1->cd();
   //TText *binlab = new TText(50,7000,binn);
   //TFile *fOut = TFile::Open(outputfile,"recreate");
   //fOut->Write();
}
