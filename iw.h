#ifndef __IW_H
#define __IW_H

#include <linux/nl80211.h>
#include <netlink/genl/genl.h>
#include <netlink/genl/family.h>
#include <netlink/genl/ctrl.h>

#define ETH_ALEN 6

struct nl80211_state {
	struct nl_handle *nl_handle;
	struct nl_cache *nl_cache;
	struct genl_family *nl80211;
};


int handle_interface(struct nl80211_state *state,
		     char *phy, char *dev, int argc, char **argv);

int handle_info(struct nl80211_state *state, char *phy, char *dev);

int handle_station(struct nl80211_state *state,
		   char *dev, int argc, char **argv);

int handle_mpath(struct nl80211_state *state,
		   char *dev, int argc, char **argv);

int handle_reg(struct nl80211_state *state,
		   int argc, char **argv);

int mac_addr_a2n(unsigned char *mac_addr, char *arg);
int mac_addr_n2a(char *mac_addr, unsigned char *arg);

const char *iftype_name(enum nl80211_iftype iftype);

#endif /* __IW_H */
