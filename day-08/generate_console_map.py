import geopandas as gpd
import matplotlib.pyplot as plt
import climage
import os

#simu
data = {
    'city': ['Paris', 'New York', 'Tokyo'],
    'lat': [48.85, 40.71, 35.67],
    'lon': [2.35, -74.00, 139.65]
}

url = "https://naturalearth.s3.amazonaws.com/110m_cultural/ne_110m_admin_0_countries.zip"
world = gpd.read_file(url)


fig, ax = plt.subplots(figsize=(10, 5))
fig.patch.set_facecolor('black')
ax.set_facecolor('black')


world.plot(ax=ax, color='#333333', edgecolor='#555555')


ax.scatter(data['lon'], data['lat'], color='red', s=100, zorder=5)


for i, txt in enumerate(data['city']):
    ax.text(data['lon'][i]+3, data['lat'][i], txt, color='white', fontsize=12, fontweight='bold')


ax.set_axis_off()

plt.savefig('temp_map.png', facecolor='black', bbox_inches='tight', pad_inches=0)
plt.close()


output = climage.convert('temp_map.png', is_unicode=True, width=120, palette="default")

print(output)


os.remove('temp_map.png')